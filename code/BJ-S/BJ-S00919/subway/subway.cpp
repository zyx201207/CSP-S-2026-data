#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,w[550000],f[510][510],x,y,ans,k,p,t,q;
struct zzh
{
    long long i,t;
};
vector<zzh> a[550010];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j) f[i][j]=1e15;
        }
    }
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>p>>t;
            a[p].push_back(zzh{i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            for(int k=0;k<a[i].size();k++)
            {
                f[a[i][j].i][a[i][k].i]=min(f[a[i][j].i][a[i][k].i],a[i][j].t+a[i][k].t);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--)
    {
        ans=1e15;
        cin>>x>>y;
        for(int i=0;i<a[x].size();i++)
        {
            for(int j=0;j<a[y].size();j++)
            {
                ans=min(f[a[x][i].i][a[y][j].i]+a[x][i].t+a[y][j].t,ans);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
}