#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,c,q;
vector<pair<int,int> >station[500001];
int graph[501][501],dis[501][501];
int w[500001];
struct state{
    int t,w;
};
bool operator<(state a,state b){
    return a.w<b.w;
}
queue<int> Q;
int addw[500001];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(graph,0x3f,sizeof(graph));
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int sta=i;
        int si;
        cin>>si;
        for(int x=1;x<=si;x++){
            int k,t;
            cin>>k>>t;
            station[k].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){      
        if(station[i].size()==1) continue;
        for(int x=0;x<station[i].size();x++){
            for(int y=0;y<station[i].size();y++){
                int t1=station[i][x].first;
                int w1=station[i][x].second;
                int t2=station[i][y].first;
                int w2=station[i][y].second;
                if(t1==t2) continue;
                graph[t1][t2]=graph[t2][t1]=min(graph[t1][t2],w1+w2);
            }    
        }
    }
    for(int i=1;i<=n;i++){
        int yd=i;
        dis[i][i]=0;
        Q.push(i);
        while(Q.size()){
            int t=Q.front();
            Q.pop();
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[i][t]+graph[t][j]){
                    dis[i][j]=dis[i][t]+graph[t][j];
                    Q.push(j);
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=LLONG_MAX;
        for(int i=0;i<station[x].size();i++){
            for(int j=0;j<station[y].size();j++){
                if(ans>dis[station[x][i].first][station[y][j].first]+station[y][j].second+station[x][i].second+w[x]+w[y]) ans=dis[station[x][i].first][station[y][j].first]+station[y][j].second+station[x][i].second+w[x]+w[y];
            }
        }
        cout<<ans<<'\n';
    }
    //17:56 AC
}   