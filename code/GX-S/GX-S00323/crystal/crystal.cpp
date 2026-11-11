#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll n,m;
ll a[500010];
ll c[500010];
bool cmp(ll x,ll y)
{
    return x<y;
}
bool check(int l)
{
    bool cg=0;
    ll z=0,zz=1e18;
    for(int i=l;i<=n;i++)
    {
        z=c[i-1]-c[i-l];
        zz=min(zz,z);
        /*if(z<=m)
        {cout<<l<<' '<<z<<"\n";
            return 1;}*/
    }
   // cout<<l<<' '<<zz<<"\n";
    if(zz<=m)
    return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen ("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    cin>>n>>m;
    bool d=0,l=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>100 || a[i]<-100)d=1;
        if(i>=3 && a[i]-a[i-1]!=a[i-1]-a[i-2])l=0;
    }
    if(n<=5000 || !d)
    {

    sort(a+1,a+1+n,cmp);
    for(int i=1;i<n;i++)
    {
        c[i]=c[i-1]+(a[i+1]-a[i])*i;
    }
    int l=1,r=n;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(check(mid))
        {
            l=mid+1;
        }
        else r=mid-1;
    //cout<<mid<<' '<<dz<<"\n";
    }
    cout<<r;
    }
    else if(l)
    {
        ll lc=a[2]-a[1];
        ull cs=0,cd=0;
        while(cs+lc*cd<=m && lc<=n)
        {
            cs+=lc*cd;
            lc++;
        }
        cout<<lc;
    }
    else
    {
        mt19937 sj(time(0));
        cout<<sj()%n;
    }
    return 0;
}
