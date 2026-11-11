#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int maxm = 4e6 + 10;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int c,t,cnt,head[maxn],s,js,flag[maxn];
ll x[maxn],dist[maxn];
bool vis[maxn];
map<ll,int> mp;
struct Edge{
    int to;
    int next;
}edge[maxm*2+1];
struct Edge2{
    int bh;
    ll w;
    bool operator<(const Edge2 & zyy)const{
        return zyy.w<w;
    }
};
void add(int u,int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void Dijkstra(){
    memset(vis,false,sizeof(vis));
    memset(dist,INF,sizeof(dist));
    priority_queue<Edge2> q;
    dist[s]=0;
    q.push({s,dist[s]});
    while(!q.empty()){
        Edge2 zyy=q.top();
        q.pop();
        int u=zyy.bh;
        if(vis[u]){
            continue;
        }
        vis[u]=true;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(dist[v]>dist[u]+1){
                dist[v]=dist[u]+1;
                q.push({v,dist[v]});
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        mp.clear();
        int n;
        ll d;
        ll cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(x[i]-x[j])<=d){
                    add(i,j);
                    flag[i]=j;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(flag[i]==0){
                    break;
                }
                s=i;
                js=j;
                Dijkstra();
                mp[dist[js]]++;
            }
            for(auto zyy:mp){
                if(zyy.second==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}