#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int c,n,m,d,q;
int ww[500010];
vector<pii>a[500010];
ll dis[510][510];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>ww[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int v,w;
            cin>>v>>w;
            a[v].push_back({i,w});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++)
    {
        for(pii j:a[i])
        {
            for(pii k:a[i])
            {
                dis[j.first][k.first]=j.second+k.second;
            }
        }
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j]) dis[j][i]=dis[i][j]=dis[i][k]+dis[k][j];

            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(pii i:a[x])
        {
            for(pii j:a[y])
            {
                ans=min(ans,i.second+j.second+dis[i.first][j.first]);
            }
        }
        cout<<ww[x]+ww[y]+ans<<endl;
    }
    return 0;
}
