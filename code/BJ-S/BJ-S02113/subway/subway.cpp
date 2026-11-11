#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+8;
const int INF = 0x3f3f3f3f;
int c,n,m,d,q,k;
int ww[N],a[N],chng[N],dis[N*40];
int cnt[500005];
bool vis[N*40];
struct node{
    int v,w;
    bool operator < (const node &rhs) const{
        return rhs.w < w;
    }
};
vector<node>adj[40*N];



struct ques{
    int x,y,id,ans;
}qq[100005];

bool cmp(ques a, ques b){
    return a.x < b.x;
}
bool cmp2(ques a, ques b){
    return a.id < b.id;
}

void dij(int s){
    priority_queue<node>q;
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    q.push({s,0});
    while(q.size()){
        int u = q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].v, w = adj[u][i].w;
            dis[v] = min(dis[v],dis[u]+w);
            q.push({v,dis[v]});
        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m>>d >>q;

    for(int i = 1; i <= m; i++){
        cin >> ww[i];
        adj[i].push_back({i+m,ww[i]});
        adj[i+m].push_back({i,ww[i]});
    }


    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int u = 1; u <= k; u++){
            cin >> a[u] >> chng[u];
        }
        for(int u = 1; u <= k; u++){
            adj[a[u]+m].push_back({a[u]+(i+1)*m,chng[u]});
            adj[a[u]+(i+1)*m].push_back({a[u]+m,chng[u]});
            if(u != 1){
                adj[a[u]+(i+1)*m].push_back({a[u-1]+(i+1)*m,0});
                adj[a[u-1]+(i+1)*m].push_back({a[u]+(i+1)*m,0});
            }
        }
    }

    for(int i = 1; i <= q; i++){
        cin >> qq[i].x >> qq[i].y;
        qq[i].id = i;
    }

    sort(qq+1,qq+q+1,cmp);

    int l = 1,r=1;
    for(int i = 1; i <= q; i++) cnt[qq[i].x]++;
    int pos = 1;
    for(int i = 1; i <= q;i += cnt[qq[i].x]){
        dij(qq[i].x);
        for(int j = i; j <= i+cnt[qq[i].x]-1; j++) qq[j].ans = dis[qq[j].y];
    }

    sort(qq+1,qq+q+1,cmp2);

    for(int i = 1; i <= q; i++) cout << qq[i].ans << endl;
    return 0;
}
