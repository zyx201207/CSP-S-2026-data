#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    string s = "";
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        char c;
        cin >> x >> c;
        for (int j = 1; j <= x; j++) s += c;
    }
    string t = s;
    reverse(s.begin() , s.end());
    if (t == s)
    {
        cout<< 0;
        return 0;
    }
    long long ans = 0;
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != t[i]) ans++;
    cout<< ans;
    return 0;
}
