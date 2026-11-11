#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 12;
int n;
long long m;
long long a[MAXN],s[MAXN];
bool check(int k)
{
    for (int r=k;r<=n;r++)
    {
        long long cur = 1ll*a[r]*k - (s[r] - s[r-k]);
        if (cur<=m) return 1;
    }
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
    int l = 1,r = n,res = 0,md;
    while (l<=r)
    {
        md = (l+r)>>1;
        if (check(md)) res = md,l = md+1;
        else r = md-1;
    }
    cout << res << '\n';
    return 0;
}