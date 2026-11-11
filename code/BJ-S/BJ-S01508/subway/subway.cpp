#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct c
{
    long long v,t;
} a[N][22];
int cnt[N];
int w[N];
long long f[550][550];
int c,n,m,d,q;
long long ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q; 
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
             cnt[x]++;
            a[x][cnt[x]].v=i;
            a[x][cnt[x]].t=y;
        }
    }
   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j]=1e18+10;
        }
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=cnt[i];j++)
        {
            for(int k=j+1;k<=cnt[i];k++)
            {
                f[a[i][j].v][a[i][k].v]=min(f[a[i][j].v][a[i][k].v],a[i][j].t+a[i][k].t);
                f[a[i][k].v][a[i][j].v]=min(f[a[i][k].v][a[i][j].v],a[i][j].t+a[i][k].t);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ans=1e18+10;
        for(int i=1;i<=cnt[x];i++)
        {
            for(int j=1;j<=cnt[y];j++)
            {
                ans=min(ans,f[a[x][i].v][a[y][j].v]+a[x][i].t+a[y][j].t);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}