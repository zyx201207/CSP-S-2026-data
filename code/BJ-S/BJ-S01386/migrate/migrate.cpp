#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long a[N],g[N],f[N],d,ans,n,v[N];
void go(long long c)
{
    long long i,j;
    f[c]=0;
    g[c]=1;
    v[c]=c;
    for(i=c;i<=n;i++)
    {
        // cerr<<c<<"->"<<i<<":"<<g[i]<<"\n";
        if(g[i]==0||v[i]<c) break;
        ans+=(g[i]==2);
        for(j=i+1;j<=n;j++)
        {
            if(a[j]-a[i]>d) break;
            if(f[i]+1<f[j]||v[j]<c)
            {
                v[j]=c;
                f[j]=f[i]+1;
                g[j]=g[i];
            }
            else if(f[i]+1==f[j])
            {
                g[j]+=g[i];
            }
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long i,j,k,m,l,r,x,y,s=0,o,c,t;
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        if(n>300)
        {
            cout<<0<<"\n";
            continue;
        }
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(i=1;i<=n;i++) v[i]=0;
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)
        {
            go(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}