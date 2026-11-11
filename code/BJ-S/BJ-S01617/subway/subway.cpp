#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505;
const int maxm=5e5+5;
int c,n,m,d,q,w[maxm],k[maxn],ct[maxm],a[maxm],t[maxm],sum[maxn],x,y,st,ed;
ll dis[maxn][maxn],ans;
pair<int,int>thg[maxm][25];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[sum[i]+j]>>t[sum[i]+j];
            thg[a[sum[i]+j]][++ct[a[sum[i]+j]]]=make_pair(i,j);
        }
        sum[i+1]=sum[i]+k[i];
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=2e18;
    for(int x=1;x<=m;x++)
    {
        for(int i=1;i<=ct[x];i++)
        {
            for(int j=i+1;j<=ct[x];j++)
            {
                st=thg[x][i].first,ed=thg[x][j].first;
                dis[st][ed]=dis[ed][st]=min(dis[st][ed],(ll)(t[sum[st]+thg[x][i].second]+t[sum[ed]+thg[x][j].second]));
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        ans=2e18;
        cin>>x>>y;
        for(int i=1;i<=ct[x];i++)
        {
            for(int j=1;j<=ct[y];j++)
            {
                st=thg[x][i].first,ed=thg[y][j].first;
                if(st==ed) ans=min(ans,(ll)(t[sum[st]+thg[x][i].second]+t[sum[ed]+thg[y][j].second]));
                else ans=min(ans,(ll)(t[sum[st]+thg[x][i].second]+t[sum[ed]+thg[y][j].second]+dis[st][ed]));
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
