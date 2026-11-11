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
vector<nd> l[N+200];
bool fg[N],vis[N+200],te[N+200],can[2000][2000];
struct eg{
    int v,w;
    bool operator<(const eg p)const{
        return p.w>w;
    }
};
int c,n,m,d,q,w[N],dy[N],dis[N+200];
void bfs(int s){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<eg> q;
    q.push({s,0});
    //cout<<s<<endl;
    while(!q.empty()){
        int u=q.top().v; q.pop();
        //cout<<u<<" "<<dis[u]<<endl;
        //cout<<u<<endl;
        if(vis[u]) continue;
        vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,w=g[u][i].t;
			//cout<<v<<" "<<w<<endl;
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
    memset(ts,0x3f,sizeof(ts));
    fu1(i,m,1) cin>>w[i];
    fu1(i,n,1){
        int k; cin>>k;
        int lv,lt;
        fu1(j,k,1){
            cin>>a[j].v>>a[j].t;
            can[i][a[j].v]=1;
            ts[i][j]=a[j].t;
            //l[i].pb()
            l[a[j].v].pb({a[j].t,i});
            //cout<<a[i].v<<" "<<
            if(j==1) {lv=a[j].v,lt=a[j].t;continue;}
            g[(i-1)*10+a[j].v].pb({(i-1)*10+lv,0}),g[(i-1)*10+lv].pb({(i-1)*10+a[j].v,0});
            //cout<<i<<" "<<a[j].v<<endl;
        }
        memset(fg,0,sizeof(0));
        /*
        fu1(j,k,1){
            dy[a[j].v]=j;
            fg[a[j].v]=1;
            la[j].v=a[j].v,la[j].t=a[j].t;
        }
        */
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<l[i].size();j++){
            for(int e=j+1;e<l[i].size();e++){
                //cout<<l[i][j].t<<" "<<l[i][e].t<<endl;
                g[(l[i][j].t-1)*10+i].pb({(l[i][e].t-1)*10+i,l[i][j].v+l[i][e].v});
                g[(l[i][e].t-1)*10+i].pb({(l[i][j].t-1)*10+i,l[i][e].v+l[i][j].v});
            }
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
        int ans=0x3f3f3f3f;
        //cout<<1<<endl;
        for(int i=1;i<=n;i++){
            if(can[i][u]) bfs(10*(i-1)+u);
            int d0=0x3f3f3f3f;
            for(int j=1;j<=n;j++)
                d0=min(dis[10*(j-1)+v]+ts[j][v]+ts[i][u],d0);
            ans=min(ans,d0);
        };
        //cout<<1<<endl;
        cout<<w[u]+w[v]+ans<<"\n";
    }
    return 0;
}
