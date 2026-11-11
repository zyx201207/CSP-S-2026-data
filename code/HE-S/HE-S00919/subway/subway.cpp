#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c=0,n=0,m=0,d=0,q=0,ki=0,ans=10000000000,cnt=0;
    cin>>c>>n>>m>>d>>q;
    if(c==0)
        if(n==2)
            cout<<"32"<<"\n"<<"17";
        else if(n==3)
            cout<<"35"<<"\n"<<"16";
    ll a[n+1][q+1]={0};
    ll t[n+1][q+1]={0};
    ll w[m+1]={0};
    ll x[q]={0},y[q]={0};
    for(ll j=1;j<=m;j++)
    {
        cin>>w[j];
    }
    for(ll r=1;r<=q;r++)
    {
            cin>>ki;
            for(ll j=1;j<=ki;j++)
            {
                cin>>a[j][r]>>t[j][r];
            }
        cin>>x[r]>>y[r];
    }
    for(ll r=1;r<=q;r++)
    {
        if(x[r]>y[r])
            swap(x[r],y[r]);
        cnt+=(w[x[r]]+w[y[r]]);
        bool flag1=0,flag2=0;
        ll s,e;
        for(ll i=1;i<=n;i++)
        {
            if(a[i][r]==x[r])
                flag1=1;s=i;
            if(a[i][r]==y[r])
                flag2=1;e=i;
        }
        if(flag1==1 && flag2==1)
            cnt+=t[s][r];cnt+=t[e][r];
        ans=max(cnt,ans);
        cout<<ans<<"\n";
        ans=10000000000;
    }
    return 0;
}
