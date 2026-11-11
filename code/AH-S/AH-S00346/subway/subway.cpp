#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5,N=510;
const int INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int kou[M];
struct node{
    int v,w;
    bool operator < (const node &a) const {
        return a.w<w;
    }
};
struct node2{
    int v,w;
};
vector<node> g[M+N];
int dis[1510][1510];
bool flag[1510],vis[1510][1510];
bool lj[N][N],f[N];
vector<int> hc[M];
void dij(int S,int T){
    for(int i=1;i<=1505;i++){
        dis[S][i]=INF;
    }
    dis[S][S]=0;
    priority_queue<node> q;
    q.push({S,0});
    while(!q.empty()){
        node nw=q.top();
        q.pop();
        if(vis[S][nw.v]){
            continue;
        }
        int v=nw.v;
        vis[S][v]=1;
        for(int i=0;i<g[v].size();i++){
            int tv=g[v][i].v,tw=g[v][i].w;
            if(dis[S][tv]>dis[S][v]+tw){
                dis[S][tv]=dis[S][v]+tw;
                q.push({tv,dis[S][tv]});
            }
        }
    }
}
int bfs(int S,int T){
    memset(f,0,sizeof(f));
    queue<node2> q;
    q.push({S,0});
    f[S]=1;
    while(!q.empty()){
        node2 nw=q.front();
        q.pop();
        int v=nw.v,w=nw.w;
        if(v==T){
            return w;
        }
        for(int i=1;i<=n;i++){
            if(lj[v][i]==1&&f[i]==0){
                q.push({i,w+1});
                f[i]=1;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>kou[i];
    }
    if(c<=11){
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            while(k--){
                int ta,tt;
                cin>>ta>>tt;
                g[ta].push_back({m+i,tt});
                g[m+i].push_back({ta,tt});
            }
        }
        while(q--){
            int S,T;
            cin>>S>>T;
            if(flag[S]){
                cout<<dis[S][T]+kou[S]+kou[T]<<endl;
                continue;
            }
            flag[S]=1;
            dij(S,T);
            cout<<dis[S][T]+kou[S]+kou[T]<<endl;
        }
    }else if(c>=12&&c<=19){
        int Time=0;
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            while(k--){
                int ta,tt;
                cin>>ta>>tt;
                Time=tt;
                hc[ta].push_back(i);
            }
        }
        //cout<<"OK!"<<endl;
        for(int i=1;i<=m;i++){
            for(int j=1;j<hc[i].size();j++){
                lj[hc[i][j-1]][hc[i][j]]=1;
                lj[hc[i][j]][hc[i][j-1]]=1;
            }
        }
        //cout<<"OK!"<<endl;
        while(q--){
            int S,T;
            cin>>S>>T;
            int cnt=INF;
            for(int i=0;i<hc[S].size();i++){
                for(int j=0;j<hc[T].size();j++){
                    cnt=min(cnt,bfs(hc[S][i],hc[T][j]));
                }
            }
            //cout<<cnt<<"\n";
            cout<<cnt*2*Time+kou[S]+kou[T]+2*Time<<endl;
        }
        //cout<<"OK!"<<endl;
    }
    return 0;
}
