#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[maxn];
int n,m;
int sum[maxn];
bool check(int mid,int k)
{
    return a[k]*(k-mid+1)-(sum[k]-sum[mid-1])<=m;
}
int bs(int l,int r,int k)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid,k))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return r;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++)sum[i]=sum[i-1]+a[i];
    int ans=1;
    for(int i=1; i<=n; i++)
    {
        ans=max(ans,i-bs(1,i,i)+1);
        //cout<<bs(1,i,i)<<" "<<i<<endl;
    }
    cout<<ans;
    return 0;
}
