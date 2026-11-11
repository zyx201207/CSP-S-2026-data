#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e5+10,MAXN=505,MAXD=25;
int w[MAXM],cnt[MAXM],a[MAXM][MAXD];
long long dis[MAXN][MAXN],t[MAXM][MAXD];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >>q;
    for (int i=1;i<=m;i++)cin >> w[i];
    for (int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        for (int j=1;j<=k;j++)
        {
            int x;
            cin >> x;
            a[x][++cnt[x]]=i;
            cin >> t[x][cnt[x]];
        }
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=cnt[i];j++)
        {
            for (int k=j+1;k<=cnt[i];k++)
            {
                dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
            }
        }
    }
    for (int i=1;i<=n;i++)dis[i][i]=0;
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    /*
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }
    */
    while (q--)
    {
        int u,v;
        cin >> u >>v;
        long long ans=1e18;
        for (int i=1;i<=cnt[u];i++)
        {
            for (int j=1;j<=cnt[v];j++)
            {
                ans=min(ans,t[u][i]+t[v][j]+dis[a[u][i]][a[v][j]]+w[u]+w[v]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
