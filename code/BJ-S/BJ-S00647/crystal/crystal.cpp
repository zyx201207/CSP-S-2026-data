#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],ans,m,b[500005];
bool check(int mid,int n)
{
    int nn=n-mid+1;
    for(int i=1;i<=nn;i++)
    {
        if(b[i+mid-1]-b[i-1]-mid*(b[i+mid-1]-b[i+mid-2])<=m)
        {
            return true;
        }
    }
    return false;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[0]=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=b[i-1]+a[n]-a[i];
    }
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid,n))
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<ans<<endl;
}