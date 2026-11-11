#include<iostream>

#define ll long long

int main(int argc, char **argv){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    
    ll n, d;

    std::cin >> n >> d;
    std::cout << d - 1<< '\n';

    return 0;
}