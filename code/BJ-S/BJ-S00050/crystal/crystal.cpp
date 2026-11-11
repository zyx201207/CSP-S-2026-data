#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],qz0[500005],qz1[500005];
//               a[i]<=0     a[i]>0
bool sp_ab/*特殊性质A&B*/=true;ll cha=0;
ll ans=0;
ll cal_ab(ll a1,ll ax,ll x)
{
    return (ax-a1)*(x-1)/2;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==2)
        {
            cha=a[2]-a[1];
        }
        else if(i>2)
        {
            if(a[i]-a[i-1]!=cha)
            {
                sp_ab=false;
            }
        }
    }
    if(sp_ab)
    {
        for(int i=2;i<=n;i++)
        {
            ll rst=cal_ab(a[1],a[i],i);
            if(rst<m)
            {
                ans=i;
            }
            else if(rst==m)
            {
                ans=i;
                break;
            }
            else
            {
                break;
            }
        }
        cout<<ans<<"\n";
        return 0;
    }
    sort(a+1,a+n+1);
    ll f1_=-1,f0=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=0)
        {
            qz0[i]=qz0[i-1]+a[i];
        }
        else
        {
            if(a[i]>0 && a[i-1]<=0)
            {
                f1_=i;
            }
            qz1[i]=qz1[i-1]+a[i];
        }
    }
    int i=0;
    for(i=2;i<=n;i++)
    {
        //cout<<"n:"<<n<<"  m:"<<m<<"\n";
        ll les=0;
        if(i<f1_)
        {
            les=abs(qz0[i])-abs(a[i]*i);
            //cout<<"{<=0}"<<"i:"<<i<<"  f1_:"<<f1_<<"  qz0["<<i<<"]:"<<qz0[i]<<"  les:"<<les<<"\n";
        }
        else if(i>=f1_)
        {
            les=a[i]*i-qz1[i]-qz0[f1_-1];
            //cout<<"{>0}"<<"i:"<<i<<"  f1_:"<<f1_<<"  qz0["<<f1_-1<<"]:"<<qz0[f1_-1]<<"  qz1["<<i<<"]:"<<qz1[i]<<"  les:"<<les<<"\n";
        }
        if(les<=m)
        {
            continue;
        }
        else
        {
            cout<<i-1<<"\n";
            return 0;
        }

    }
    cout<<i<<"\n";
    return 0;
}
