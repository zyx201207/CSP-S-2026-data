#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e3+5;
int c,n,m,d,q;
int w[M],k[M],a[505][M],dis[M];
ll t[505][M];
vector<int> belong[505];
vector<int> e[M];
vector<int> r[M];
int vis[M];
void dfs(int u,int fa){
    for(auto v:r[u]){
        if(v==fa||vis[v]) continue;
        dis[v]=min(dis[v],dis[u]+1);
        vis[v]=1;
        dfs(v,u);
    }
    return;
}
bool checkA(){
    for(int i=1;i<=n;++i) if(k[i]>2) return false;
    return true;
}
/*bool checkB(){
    int tot=0;ll T;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k[i];++j){
            ++tot;
            if(tot==1) T=t[i][j];
            if(t[i][j]!=T) return false;
        }
    }
    return true;
}*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=m;++i) dis[i]=1e9;
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j){
            cin>>a[i][j]>>t[i][j];
            belong[a[i][j]].push_back(i);
            e[i].push_back(a[i][j]);
        }
    }
    if(checkA()){
        for(int i=1;i<=n;++i){
            if(k[i]==2){
                r[a[i][1]].push_back(a[i][2]);
                r[a[i][2]].push_back(a[i][1]);

            }            
        }
        for(int i=1;i<=n;++i){
            int x,y;
            cin>>x>>y;
            if(a[i][1]==x){
                dis[a[i][2]]=1;
                dfs(a[i][2],a[i][1]);
                
            }
            else if(a[i][2]==x){
                dis[a[i][1]]=1;
                dfs(a[i][1],a[i][2]);

            }
            cout<<w[x]+w[y]+2*(dis[y])<<'\n';
        }
    }
    return 0;
}