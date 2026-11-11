//GZ-S00085 ³ÂÜÆåû
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
const int N=505;
vector<pii> e[N];
void ss()
{
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int>a(m+1);
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int lst=0;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            e[i].push_back({x,y});
        }
    }
    if(m<=500)
    {
        vector<vector<ll>>dis(m+1,vector<ll>(m+1,1e18));
        for(int i=1;i<=n;i++)
        {
            ll id=0;
            for(auto [x,y]:e[i])
            {
                if(id) dis[x][id]=dis[id][x]=min(dis[id][x],y);
                dis[x][x]=min(dis[x][x],y);
                id=x;
            }
        }
        for(int k=1;k<=m;k++)
        {
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[k][j]+dis[i][k];
                }
            }
        }
        while(q--)
        {
            int s,t;
            cin>>s>>t;
            if(n==1) cout<<dis[s][t]+a[s]+a[t]<<"\n";
            else
            {
                ll ans=a[s]+a[t];
                for(int i=s;i<t;i++) ans+=dis[i][i]+dis[i][i+1];
                cout<<ans<<"\n";
            }
        }
    }
    else
    {
        while(q--)
        {
            int s,t;
            cin>>s>>t;
            cout<<a[s]+a[t]<<"\n";
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--) ss();
    return 0;
}
