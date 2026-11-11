#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll a[N];
ll st[N][20];
ll sum[N];
int ans=0;
ll m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]-a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=n-i;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(  (sum[i+mid-1]-sum[i-1]) + (a[i+mid-1])*mid <=m)
            {
                l=mid;
            }
            else r=mid-1;
        }
        //cout<<l<<' ';
        ans=max(ans,l);
    }
    // cout<<endl;
    cout<<ans;
    return 0;
}