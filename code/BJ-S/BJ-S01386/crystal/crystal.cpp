#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N],sum[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long i,j,k,n,m,l,r,x,y,s=0,o;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for(i=1;i<=n;i++)
    {
        // cerr<<i<<"\n";
        long long now=m;
        l=1;
        r=i;
        while(l<r)
        {
            long long mid=l+r>>1;
            // cerr<<"#"<<i<<":"<<l<<" "<<r<<"\n";
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        s=max(s,i-l+1);
    }
    cout<<s<<"\n";
    return 0;
}