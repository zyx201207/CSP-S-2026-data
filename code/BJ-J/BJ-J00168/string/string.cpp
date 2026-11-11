#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int, char> p[200005];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s;
    int n, t=0;
    bool ok=0, ok2=1;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> p[i].first >> p[i].second;
        if (p[i].second!=p[i-1].second)
            ok2=0;
        t+=p[i].first;
        if (t>=1e6)
        {
            ok=1;
        }
        if (!ok)
        for (int j=1;j<=p[i].first;j++)
            s+=p[i].second;
    }
    if (ok2)
    {
        cout <<0;
        return 0;
    }
    if (ok)
    {
        cout << t/2;
        return 0;
    }
    t-=1;
    int ans=0;
    int pos=t/2;
    for (int l=0;l<=pos;l++)
    {
        if (s[l]!=s[t-l])
            ans++;
    }
    cout << ans;
    return 0;
}
