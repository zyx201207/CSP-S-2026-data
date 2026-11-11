#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+11;
int n;
ll m,a[maxn];
bool check(ll mid)
{
    ll sum=0;
    for(int i=1;i<=n;++i)
    {
        if(i-mid>0)
            sum-=a[i-mid];
        if(i>=mid)
        {
            sum+=a[i];
            if(mid*a[i]-sum<=m)
                return 1;
        }
        else
            sum+=a[i];
    }
    return 0;
}
ll bs()
{
    ll ret=1,l=1,r=n;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
            ret=mid,l=mid+1;
        else
            r=mid-1;
    }
    return ret;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    cout<<bs()<<"\n";
    return 0;
}