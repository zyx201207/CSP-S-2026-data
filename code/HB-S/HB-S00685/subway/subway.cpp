#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int c,n,m,d,q;
int w[maxn],k[510];
vector<int> a[510],t[510];
vector<int> path[maxn];
vector<pair<int,ll> >g[maxn];
ll dis[maxn],vis[510];
ll ans[100010];
struct edge{
    int x,y,i;
}que[100010];
bool cmp(edge a,edge b){
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
struct node{
    int pathh,pos;
    bool operator < (const node &o) const{
        return (dis[pos]<dis[o.pos])||(dis[o.pos]==dis[pos]&&pathh<o.pathh);
    }
};
void dfs(int pos,int fa){
    for(int i=0,size=g[pos].size();i<size;i++){
        int to=g[pos][i].first,val=g[pos][i].second;
        if(to==fa) continue;
        if(dis[to]>dis[pos]+val){
            dis[to]=dis[pos]+val;
            dfs(to,pos);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    if(c>=7&&c<=11){
        for(int i=1;i<=n;i++){
            cin>>k[i];
            int u,v,xx1,xx2;
            cin>>u>>xx1>>v>>xx2;
            g[u].push_back({v,1ll*xx1+xx2});
            g[v].push_back({u,1ll*xx1+xx2});
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            for(int i=1;i<=m;i++)
                dis[i]=1e9;
            dis[x]=0;
            dfs(x,0);
            ll ans=dis[y]+w[x]+w[y];
            cout<<ans<<'\n';
        }
        return 0;   
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int pos,tim;
            cin>>pos>>tim;
            path[pos].push_back(i);
            a[i].push_back(pos);
            t[i].push_back(tim);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>que[i].x>>que[i].y;
        que[i].i=i;
    }
    sort(que+1,que+1+q,cmp);
    if(c>=12&&c<=19){
        int T=t[1][0];
        for(int qq=1;qq<=q;qq++){
            int x=que[qq].x,y=que[qq].y;
            if(x!=que[qq-1].x){
                for(int i=1;i<=n;i++)
                    vis[i]=0;
                for(int i=1;i<=m;i++)
                    dis[i]=1e9;
                dis[x]=0;
                priority_queue<node> q;
                for(int kk:path[x]){
                    q.push({kk,x});
                }
                while(!q.empty()){
                    int pos_path=q.top().pathh;
                    int pos=q.top().pos;
                    q.pop();
                    if(vis[pos_path]) continue;
                    vis[pos_path]=1;
                    for(int to:a[pos_path]){
                        if(dis[to]>dis[pos]+1){
                            dis[to]=dis[pos]+1;
                            for(int kk:path[to])
                                if(vis[kk]==0) q.push({kk,to});
                        }
                    }
                }
            }
            int cnt=dis[y];
            ans[que[qq].i]=2ll*cnt*T+w[x]+w[y];
        }
        for(int i=1;i<=q;i++)
            cout<<ans[i]<<'\n';
        return 0;
    }
    for(int qq=1;qq<=q;qq++){
        int x=que[qq].x,y=que[qq].y;
        if(x!=que[qq-1].x){
            for(int i=1;i<=m;i++)
                dis[i]=1e9;
            dis[x]=0;
            priority_queue<node> q;
            for(int kk:path[x]){
                q.push({kk,x});
            }
            while(!q.empty()){
                int pos_path=q.top().pathh;
                int pos=q.top().pos,w=0;
                q.pop();
                for(int i=0;i<k[pos_path];i++){
                    int to=a[pos_path][i],val=t[pos_path][i];
                    if(to==pos) w=val;
                }
                for(int i=0;i<k[pos_path];i++){
                    int to=a[pos_path][i],val=t[pos_path][i];
                    if(dis[to]>dis[pos]+w+val){
                        dis[to]=dis[pos]+w+val;
                        for(int kk:path[to])
                            q.push({kk,to});
                    }
                }
            }
        }
        ans[que[qq].i]=dis[y]+w[x]+w[y];
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<'\n';
    return 0;
}