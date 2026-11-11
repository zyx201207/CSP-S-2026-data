#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int f[505][505];
vector<pair<int,int>> sub[500005];
void build(){
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++) for(auto p:sub[i]){
        int x=p.first;
        int t=p.second;
        for(auto p:sub[i]){
            int nx=p.first;
            int nt=p.second;
            f[x][nx]=min(f[x][nx],t+nt);
            f[nx][x]=min(f[nx][x],t+nt);
        }
    }
}
void Floyd(){
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int x,t;
            cin>>x>>t;
            sub[x].push_back({i,t});
        }
    }
    build();
    Floyd();
    while(q--){
        int s,t;
        cin>>s>>t;
        int dis=0x3f3f3f3f3f3f3f3f;
        for(auto p:sub[s]) for(auto q:sub[t]){
            int x=p.first;
            int nx=q.first;
            int tim=p.second;
            int ntim=q.second;
            dis=min(dis,f[x][nx]+tim+ntim+w[s]+w[t]);
        }
        cout<<dis<<"\n";
    }
}