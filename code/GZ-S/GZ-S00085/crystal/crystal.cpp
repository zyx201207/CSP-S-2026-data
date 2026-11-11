//GZ-S00085 ³ÂÜÆåû
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void ss()
{
    ll n,m,mx=1;
    cin>>n>>m;
    vector<ll>a(n+1);
    bool f=1;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=3;i<=n;i++)
    {
        if(a[i]-a[i-1]!=a[2]-a[1])
        {
            f=0;break;
        }
    }
    if(f)
    {
        for(int i=n;i>=1;i--)
        {
            if((i-1)*i/2*(a[2]-a[1])<=m)
            {
                cout<<i<<"\n";
                return;
            }
        }
    }
    sort(a.begin(),a.end());
    vector<ll>dis(n+1,0);
    for(int i=2;i<=n;i++) dis[i]=dis[i-1]+i*(a[i]-a[i-1]);
    auto id=upper_bound(dis.begin(),dis.end(),m)-dis.begin()-1;
    if(id==1)
    {
        cout<<"1\n";
        return;
    }
    if(n<=5000)
    {
        mx=id;
        for(ll i=n;i>id;i--)
        {
            if(dis[i]<=m)
            {
                cout<<max(mx,i)<<"\n";
                return;
            }
            else
            {
                ll cnt=0,c1=1,id=i-1;
                while(id>=1&&a[i]-a[id]<=m&&cnt<=m-a[i]+a[id])
                {
                    cnt+=a[i]-a[id];
                    c1++;
                    id--;
                }
                mx=max(mx,c1);
            }
        }
        cout<<mx<<"\n";
    }
    else
    {
        for(int i=n;i>=1;i--)
        {
            if(dis[i]<=m)
            {
                cout<<i<<"\n";
                return;
            }
        }
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--) ss();
    return 0;
}
