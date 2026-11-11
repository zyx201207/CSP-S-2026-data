#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
int n,m,a[N],sum[N],ans=1;
int cmp(int aa,int bb) { return aa<bb; };
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=2,l=1;i<=n;i++)
    {
        while(l<i&&sum[i-1]-sum[l-1]+m<a[i]*(i-l)) l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/
