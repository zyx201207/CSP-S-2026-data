#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s1, s2;
    while(n--)
    {
        int a;
        char c;
        cin >> a >> c;
        while(a--)
        {
            s1 += c;
            s2 = c + s2;
        }
    }
    long long cnt = 0;
    for (int i = 0 ; i < s1.size() ; i++)
    {
        if(s1[i] != s2[i])cnt++;
    }
    cout << cnt / 2;
    fcloseall();
    return 0;
}
