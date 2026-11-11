#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int w[500010];
vector<int>g[500010],l[500010];
int dist[1010][1010];
int t[1010][1010];
void dfs(int x,int now,int dis,int st,bool flag){
    if(dis+t[x][now]>=dist[st][x]&&st!=x){
        return;
    }
    dist[st][x]=dis+t[x][now];
    dist[x][st]=dis+t[x][now];
    for(auto i:l[x]){
        if(i==now){
            for(auto j:g[i]){
                if(j!=x&&!flag){
                    dfs(j,now,dis,st,1);
                }
            }
        }else{
            for(auto j:g[i]){
                if(j!=x){
                    dfs(j,i,dis+t[x][i]+t[x][now],st,0);
                }
            }
        }
    }
    return;
}
bool cross[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=m;i++){
        cin>>w[i];
        dist[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            cin>>t[x][i];
            g[i].push_back(x);
            l[x].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        for(auto j:l[i]){
            dfs(i,j,t[i][j],i,0);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dist[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}