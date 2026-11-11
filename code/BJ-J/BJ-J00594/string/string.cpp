#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,a,ans = 0;
    char c;
    string s = "";
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a >> c;
        string _(a,c);
        s += _;
    }
    for (int i = 0;i < s.length() / 2;i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}