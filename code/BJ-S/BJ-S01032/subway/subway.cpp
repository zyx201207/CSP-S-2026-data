#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans=INT_MAX,vis[500050],t[600],k[500050][550];
long long a[500050];
struct N{
    long long num, stsj;
}b[600][500050];
map<long long,long long> ma;
map<long long,long long> maa;
vector<long long> g[500050];
void dfs(long long u, long long sum, long long target,long long last){
    if (u==target){
        ans=min(ans,sum+a[target]);
        return;
    }
    for (long long i=0;i<g[u].size();i++){
        long long v=g[u][i];
        if (vis[v]==0){
            vis[v]=1;
            if (maa[u]==0){
                if (maa[last]!=maa[v]){
                    if (maa[last]==1000){
                         dfs(v,sum+k[u][maa[v]],target,u);
                    }
                    else{
                        dfs(v,sum+k[u][maa[v]]+k[v][maa[v]],target,u);
                    }
                }
                else{
                    dfs(v,sum,target,u);
                }
            }
            else{
                dfs(v,sum,target,u);
            }
            vis[v]=0;
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (long long i=1;i<=m;i++){
        cin >> a[i];
    }
    for (long long i=1;i<=n;i++){
        cin >> t[i];
        cin >> b[i][1].num >> b[i][1].stsj;
        ma[b[i][1].num]++;
        maa[b[i][1].num]=i;
        k[b[i][1].num][i]=b[i][1].stsj;
        for (long long j=2;j<=t[i];j++){
            cin >> b[i][j].num >> b[i][j].stsj;
            maa[b[i][j].num]=i;
            ma[b[i][j].num]++;
            k[b[i][j].num][i]=b[i][j].stsj;
        }
    }
    for (long long i=1;i<=n;i++){
        for (long long j=2;j<=t[i];j++){
            if (ma[b[i][j].num]>1){
                maa[b[i][j].num]=0;
            }
            g[b[i][j].num].push_back(b[i][j-1].num);
            g[b[i][j-1].num].push_back(b[i][j].num);
        }
    }
    maa[0]=1000;
    while(q--){
        long long s,e;
        cin >> s >> e;
        memset(vis,0,sizeof(vis));
        vis[s]=1;
        dfs(s,a[s],e,0);
        cout << ans << endl;
    }
    return 0;
}
