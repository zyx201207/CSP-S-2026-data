#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=505,M=5e5+10;
ll c,n,m,d,q,w[M],t[N][M],wei[N][N],e[M][25],cnt[M];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);

    cin >> c >> n >> m >> d >> q;
    for(ll i=1;i<=m;i++)cin >> w[i];
    memset(wei,0x3f,sizeof wei);
    for(ll i=1;i<=n;i++)wei[i][i]=0;
    for(ll i=1,k;i<=n;i++)
    {
        cin >> k;
        for(ll j=1,x,y;j<=k;j++)
        {
            cin >> x >> y;
            t[i][x]=y;e[x][++cnt[x]]=i;
            for(ll p=1;p<i;p++)
            {
                if(t[p][x])wei[i][p]=wei[p][i]=min(wei[i][p],t[i][x]+t[p][x]);
            }
        }
    }
    for(ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                wei[i][j]=wei[j][i]=min(wei[i][j],wei[i][k]+wei[k][j]);
            }
        }
    }
    for(ll temp=1;temp<=q;temp++)
    {
        ll x,y,ans=1e18;
        cin >> x >> y;
        for(ll i=1;i<=cnt[x];i++)
        {
            for(ll j=1;j<=cnt[y];j++)
            {
                ll xx=e[x][i],yy=e[y][j];
                ans=min(ans,w[x]+t[xx][x]+wei[xx][yy]+t[yy][y]+w[y]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
