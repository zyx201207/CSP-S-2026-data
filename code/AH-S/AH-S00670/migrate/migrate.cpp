#include<bits/stdc++.h>
using namespace std;
#define fu1(i,n,k) for(int i=1;i<=n;i+=k)
#define fd1(i,n,k) for(int i=n;i>=1;i-=k)
#define fd0(i,n,k) for(int i=n-1;i>0;i-=k)
#define pb push_back
#define ps push
#define lb(x) (x&(x-1))
const int N=2e4+10;
struct nd{int v,t;};
vector<nd> g[N+200];
nd a[N],la[N]; int ts[2000][2000];
int kp[N];
//vector<int> l[N+200];
bool fg[N],vis[N+200],te[N+200];
struct eg{
    int v,w;
    bool operator<(const eg p)const{
        return p.w>w;
    }
};
int c,n,m,d,q,w[N],dy[N],dis[N+200];
void bfs(int s,int e){
    memset(vis,0,sizeof(0));
    memset(dis,0x3f,sizeof(0));
    dis[s]=0;
    priority_queue<eg> q;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().v; q.pop();
        cout<<u<<endl;
        if(!fg[u]) fg[u]=1;
		for(int i=0;i<g[i].size();i++){
			int v=g[u][i].v,w=g[u][i].t;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
    }

}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    fu1(i,m,1) cin>>w[i];
    fu1(i,n,1){
        int k; cin>>k;
        int lv,lt;
        fu1(j,k,1){
            cin>>a[j].v>>a[j].t;
            ts[i][j]=a[i].t;
            //l[i].pb()
            if(j==1) {lv=a[i].v,lt=a[i].t;continue;}
            g[(i-1)*10+a[j].v].pb({(i-1)*10+lv,0}),g[(i-1)*10+lv].pb({(i-1)*10+a[j].v,0});
            if(fg[a[j].v]) {
                g[i*10+a[j].v].pb({(i-1)*10+lv,la[dy[a[j].v]].t+a[j].t});
                g[(i-1)*10+lv].pb({i*10+a[j].v,la[dy[a[j].v]].t+a[j].t});
            }
        }
        memset(fg,0,sizeof(0));
        fu1(j,k,1){
            dy[a[j].v]=j;
            fg[a[j].v]=1;
            la[j].v=a[j].v,la[j].t=a[j].t;
        }
    }
    /*
    for(int i=1;i<=m;i++){
        for(int j=0;j<g[i].size();j++){
            cout<<g[i][j].v<<" ";
        }
        cout<<endl;
    }
    */
    //cout<<1<<endl;
    while(q--){
        int u,v; cin>>u>>v;
        //cout<<1<<endl;
        //bfs(u);
        int d0=0x3f3f3f3f;
        for(int i=1;i<=n;i++)
            d0=min(dis[10*(i-1)+v]+ts[i][v],d0);
        cout<<endl;
        //cout<<1<<endl;
        cout<<w[u]+w[v]+d0<<"\n";

    }
    return 0;
}
