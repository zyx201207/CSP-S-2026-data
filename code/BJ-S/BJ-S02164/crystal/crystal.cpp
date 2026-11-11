#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N];
int b[N];
ll m;
int n;
map<int,int> h;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool f1=1,f2=1;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        if(m<=1000)
        {
            b[i]=a[i];
        }
        else
        {
            if(a[i]!=i) f1=0;
            if(i!=1&&((ll)(a[i]-a[i-1]))!=(ll)(a[2]-a[1])) f2=0;
        }
    }
    if(f1)
    {
        ll cnt=0,i;
        for(i=1;i<=m;i++)
        {
            if(cnt+i>m) break;
            cnt+=i;
        }
        cout<<i;
        return 0;
    }
    if(f2)
    {
        ll cnt=0,i;
        for(i=(ll)(a[2]-a[1]);i<=m;i+=(ll)(a[2]-a[1]))
        {
            if(cnt+i>m) break;
            cnt+=i;
        }
        cout<<(ll)(i/(ll)(a[2]-a[1]));
        return 0;
    }
    //sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=50;k++) h[k]=0;
        int tot=0,t=m,res;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(b[j]>b[i]) break;
            h[b[i]-b[j]]++;
            tot=max(tot,b[i]-b[j]);
        }
        for(int g=0;g<=tot;g++)
        {
            if((t-(h[g]*g))>=0)
            {
                t-=h[g]*g;
                res+=h[g];
                if((t-(h[g]*g))==0)
                {
                    break;
                }
            }
            else
            {
                t=0;
                res+=t;
                break;
            }
        }
        ans=max(ans,res+1);
    }
    cout<<ans;
    return 0;
}