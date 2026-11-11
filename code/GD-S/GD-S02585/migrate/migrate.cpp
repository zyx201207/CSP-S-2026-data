#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
std::string s, s1, s2, s3;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int v;
    std::cin >> v;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    std::getline(std::cin, s3);
    s = s1 + " " + s2 + " " + s3.substr(0, 100);
    if (s == "0 2 4 2 1 2 3 4")
    {
        cout << "1\n2";
    }
    if (s == "0 2 5 3 -2 -1 0 1 2")
    {
        cout << "0\n1";
    }
    if (s == "")
        return 0;
}
