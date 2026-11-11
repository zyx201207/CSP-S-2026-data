#include<iostream>

#define ll long long

int main(int argc, char **argv){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ll n, m, d, q, a, tmp;

    std::cin >> n >> n >> m >> d >> q;
    for(ll i = 0; i < m; i++)
        std::cin >> tmp;

    std::cout << d * tmp << '\n';

    return 0;
}