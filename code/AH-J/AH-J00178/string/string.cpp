#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 20;
int a[MAXN];
char c[MAXN];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //freopen("string.err","w",stderr);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s = "";
    int f = 1;
    int n;cin >> n;
    for(int i = 1;i <= n;i++)
    {
        if(i >= 2)
        {
            if(c[i] != c[i-1])f = 0;
        }
        cin >> a[i] >> c[i];
        for(int j = 1;j <= a[i];j++)
        {
            s += c[i];
        }
    }
    //cerr << s;
    //cerr << " " << s.size();
    if(n == 1 || f == 1)
    {
        cout << 0;
        return 0;
    }
    int ans = 0;
    for(int i = 0;i < (s.size() >> 1);i++)
    {
        if(s[i] != s[s.size() - 1 - i])
        {
            ans++;
            s[s.size()-1-i] = s[i];
        }
    }
    cout << ans;
    return 0;
}

void CSP_J(int AK)
{
    int RP = 100;
    int Inf = 0x3f3f3f3f;
    RP+=Inf;//!
}