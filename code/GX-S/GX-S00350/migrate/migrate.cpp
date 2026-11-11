#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace solve{
    const int MAXN=5005;
    vector<int> to[MAXN],from[MAXN];
    int n,d,x[MAXN],dist[MAXN][MAXN],cnt[MAXN][MAXN];
    bool check(int u,int v){
        return cnt[u][v]==2;
    }
    int dfs(int tar,int s,int t,int step){
        if(step>dist[tar][t]) return 0;
        if(s==t&&step==dist[tar][t]) return 1;
        int ret=0;
        for(auto x:to[s]){
            ret+=dfs(tar,x,t,step+1);
        }
        return ret;
    }
    void sol(){
        cin >>n >>d;
        for(int i=1;i<=n;i++) cin >>x[i];
        for(int i=1;i<=n;i++){
            to[i].clear();
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]>d) break;
                to[i].push_back(j);
            }
        }
        for(int i=n;i>=1;i--){
            from[i].clear();
            for(int j=i-1;j>=1;j--){
                if(x[i]-x[j]>d) break;
                from[i].push_back(j);
            }
        }
        for(int i=1;i<=n;i++){
            dist[i][i]=0;
            for(int j=i+1;j<=n;j++){
                if(from[j].empty()) dist[i][j]=INT_MAX;
                else dist[i][j]=dist[i][from[j].back()]+1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cnt[i][j]=dfs(i,i,j,0);
            }
        }
        int ans=0;
        for(int u=1;u<=n;u++){
            for(int v=u+1;v<=n;v++){
                if(check(u,v)) ans++;
            }
        }
        cout <<ans <<endl;
    }
};
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >>c >>t;
    while(t--){
        solve::sol();
    }
    return 0;
}
