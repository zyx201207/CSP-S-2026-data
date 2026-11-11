#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define endl '\n'
const int N=510,M=5e5+10;
int w[M];
pair<int,int> d[M][21];
int ct[M];
int dis[N][N];
const int inf=0x3f3f3f3f3f3f3f3fLL;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,td,q;
    cin >> c >> n >> m >> td >> q;
    fr(i,1,m)cin >> w[i],ct[i]=-1;
    fr(i,1,n){
        int k;
        cin >> k;
        fr(j,1,k){
            int p,c;
            cin >> p >> c;
            ct[p]++;
            d[p][ct[p]]={i,c};
        }
    }
    memset(dis,0x3f,sizeof dis);
    fr(p,1,m){
        int sz=ct[p];
        fr(u,0,sz){
            int p1=d[p][u].fi,c1=d[p][u].se;
            fr(v,u+1,sz){
                dis[p1][d[p][v].fi]=min(dis[p1][d[p][v].fi],c1+d[p][v].se);
            }
        }
    }
   // return 0;
    fr(i,1,n){
        dis[i][i]=0;
        fr(j,1,n)dis[i][j]=min(dis[i][j],dis[j][i]);
    }
    fr(k,1,n){
        fr(i,1,n){
            fr(j,1,n){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    while(q--){
        int u,v;
        cin >> u >> v;
        int ans=inf;
        for(const auto &o:d[u]){
            for(const auto &p:d[v]){
                ans=min(ans,o.se+p.se+dis[o.fi][p.fi]);
            }
        }
        cout << ans+w[u]+w[v] << '\n';
    }
    return 0;
}
