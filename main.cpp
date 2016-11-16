#include <iostream>
#include <chrono>
#include <map>

std::map< long long, std::map< long long, long long > > combinations_from;

long long smart_c_n_k(const long long n, const long long k)
{
    if (k == 0 || n == k) {
        return 1;
    }
    auto& result = combinations_from[n][k];
    if (result != 0) {
        return result;
    }
    result = smart_c_n_k(n - 1, k - 1) + smart_c_n_k(n - 1, k);
    return result;
}

long long dumb_c_n_k(const long long n, const long long k)
{
    if (k == 0 || n == k) {
        return 1;
    }
    return dumb_c_n_k(n - 1, k - 1) + dumb_c_n_k(n - 1, k);
}

int main()
{
    const auto start_smart = std::chrono::high_resolution_clock::now();
    const auto smart_result = smart_c_n_k(40, 24);
    const auto end_smart = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> smart_diff = end_smart - start_smart;
    std::cout << "Smart result: " << smart_result << std::endl;
    std::cout << "Smart duration: " << smart_diff.count() << " s.\n";

    const auto start_dumb = std::chrono::high_resolution_clock::now();
    const auto dumb_result = dumb_c_n_k(40, 24);
    const auto end_dumb = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> dumb_diff = end_dumb - start_dumb;
    std::cout << "Dumb result: " << dumb_result << std::endl;
    std::cout << "Dumb duration: " << dumb_diff.count() << " s.\n";
}
