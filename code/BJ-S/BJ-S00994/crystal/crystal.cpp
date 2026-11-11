#include<bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=5e5+5;

int n,ans;
ll m,a[N],sum[N];
ll qsum(int l,int r)
{
    return sum[r]-sum[l-1];
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    rep(i,1,n) sum[i]=sum[i-1]+a[i];
    rep(i,1,n)
    {
        int l=1,r=i;
        while(l<r)
        {
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-qsum(mid,i)>m) l=mid+1;
            else r=mid;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
//15:32