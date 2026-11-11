#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],nt[500001],l=1,nnt,ans;
signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        nnt+=(a[i]-a[i-1])*(i-l);
        //cout << nnt << endl;
        while (nnt>m)
        {
            nnt-=a[i]-a[l];
            l++;
        }
        //cout << nnt << " " << l << endl;
        ans=max(ans,i-l+1);
    }
    cout << ans;
    return 0;
}
