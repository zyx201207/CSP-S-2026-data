#include <iostream>
#include <cstdio>
using namespace std;

bool is_left(char col)
{
    return 'A' <= col && col <= 'C';
}

bool is_near(char c1, char c2)
{
    if (c1 > c2)
        swap(c1, c2);
    return c1 + 1 == c2;
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2, l1, l2;
    string s1, s2;
    char co1, co2;
    cin >> c1 >> s1 >> c2 >> s2;
    l1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    l2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    co1 = s1[2], co2 = s2[2];
    cout << (c1 == c2) << (c1 == c2 && l1 == l2) << (c1 == c2 && l1 == l2 && is_left(co1) == is_left(co2)) << (c1 == c2 && l1 == l2 && is_left(co1) == is_left(co2) && is_near(co1, co2));
    return 0;
}