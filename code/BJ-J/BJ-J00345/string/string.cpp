#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s = "";
    for(int i = 1; i <= n; i++)
    {
        int x;
        char ch;
        cin >> x >> ch;
        for(int j = 1; j <= x; j++)
            s += ch;
    }
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != s[s.size()-i-1])
        {
            ans++;
            s[i] = s[s.size()-i-1];
        }
    }
    cout << ans << endl;
    return 0;
}
