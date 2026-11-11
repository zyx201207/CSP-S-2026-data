#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5e5;
long long a[MAXN+5],d1[MAXN+5],d2[MAXN+5];
int n;
long long m;
bool check(long long x)
{
    for(int i=x;i<=n;++i)
    {
        if(d1[i]-d1[i-x+1]-(i-x)*(d2[i]-d2[i-x+1])<=m)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,less<int>());
    for(int i=2;i<=n;++i)
    {
        d2[i]=a[i]-a[i-1];
    }
    for(int i=2;i<=n;++i)
    {
        d2[i]+=d2[i-1];
        d1[i]=d1[i-1]+(i-1)*(d2[i]-d2[i-1]);
    }
    long long l=0,r=n,ans;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
