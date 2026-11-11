#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int u[1001];
int f[1001][1001];
int k[505];
vector<int> g[200005];
vector<int> a[505];
struct node{
    int id,tt;
};
node t[505][1001];
const int C=1e15;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c>=0 && c<=11){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=C;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>u[i];
            f[i][i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>t[i][j].id>>t[i][j].tt;
            }
            for(int j=1;j<=k[i];j++){
                for(int l=j+1;l<=k[i];l++){
                    f[t[i][j].id][t[i][l].id]=min(f[t[i][j].id][t[i][l].id],t[i][j].tt+t[i][l].tt);
                    f[t[i][l].id][t[i][j].id]=min(f[t[i][l].id][t[i][j].id],t[i][j].tt+t[i][l].tt);
                }
            }
        }
        for(int kk=1;kk<=m;kk++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    if(i==j) continue;
                    f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
                }
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            cout<<f[x][y]+u[x]+u[y]<<'\n';
        }
    }
    if(c>=12 && c<=19){
        int T;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=C;
            }
        }
        for(int i=1;i<=n;i++) f[i][i]=0;
        for(int i=1;i<=m;i++){
            cin>>u[i];
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                int x,y;
                cin>>x>>y;
                T=y;
                g[x].push_back(k[i]);
                a[k[i]].push_back(x);
            }
        }
        for(int i=1;i<=n;i++){
            for(auto v : a[i]){
                for(auto x : g[v]){
                    if(i==x) continue;
                    f[i][x]=f[x][i]=1;
                }
            }
        }
        for(int kk=1;kk<=n;kk++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
                }
            }
        }
        while(q--){
            int x,y;
            int ans=C;
            cin>>x>>y;
            for(auto i:g[x]){
                for(auto j:g[y]){
                    ans=min(ans,f[i][j]);
                }
            }
            cout<<ans*2*T+2*T+u[x]+u[y]<<'\n';
        }
    }
    return 0;
}
