#include<bits/stdc++.h>
#define int long long
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,sum[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    faster;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int p=0;
    for(int i=1;i<=n;i++)
    {
        while((i-p)*a[i]-(sum[i]-sum[p])>m)p++;
        ans=max(ans,i-p);
    }
    cout << ans;
    return 0;
}