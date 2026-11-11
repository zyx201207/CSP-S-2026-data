#include <bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;
int f[128];
int g[128];

bool a1, a2, a3, a4;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    f['A'] = f['B'] = f['C'] = 1;
    f['D'] = f['F'] = 2;
    g['A'] = 1;
    g['B'] = 2;
    g['C'] = 3;
    g['D'] = 5;
    g['F'] = 6;

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) a1 = 1;
    else a1 = 0;
    if(a1 && s1.substr(0, 2) == s2.substr(0, 2)) a2 = 1;
    else a2 = 0;
    if(a2 && f[s1[2]] == f[s2[2]]) a3 = 1;
    else a3 = 0;
    if(a3 && abs(g[s1[2]] - g[s2[2]]) == 1) a4 = 1;
    else a4 = 0;
    cout << a1 << a2 << a3 << a4;

    return 0;
}