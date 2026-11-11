#include <iostream>
#include <vector>
using namespace std;
const int MAXN=505,MAXM=500005;
const long long inf=1000000000000000000;
int c,n,m,d,q,ki,a,u,v;
long long w[MAXM],t,ds[MAXN][MAXN],ls,ans;
vector<long long> z[MAXM];
vector<int> g[MAXM];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> ki;
        for(int j = 1;j <= ki;j++){
            cin >> a >> t;
            g[a].push_back(i);
            z[a].push_back(t);
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i==j) continue;
            ds[i][j]=inf;
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j < g[i].size();j++){
            for(int k = 0;k < j;k++){
                ls=z[i][j]+z[i][k];
                u=g[i][j],v=g[i][k];
                if(ds[u][v]>ls) ds[u][v]=ds[v][u]=ls;
            }
        }
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                ds[i][j]=min(ds[i][j],ds[i][k]+ds[k][j]);
            }
        }
    }
    while(q--){
        cin >> u >> v;
        ans=inf;
        for(int i = 0;i < g[u].size();i++){
            for(int j = 0;j < g[v].size();j++){
                ans=min(ans,z[u][i]+ds[g[u][i]][g[v][j]]+z[v][j]);
            }
        }
        cout << ans+w[u]+w[v] << "\n";
    }
    return 0;
}