#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 10;

struct node{
    int v,w;
    
};

bool operator <(const node x,const node y){
	return x.v > y.v;
}

int id,n,m,d,q;
int w[N];
int tot,c[N],s[N];
int tms[N];
vector <int> a[N],t[N],rk[N];
vector <node> F[N],G[N];
priority_queue <node> Q;
int dis[505][505],vis[505];

void dijkstra(int u){
    memset(dis[u],0x3f,sizeof(dis[u]));
    memset(vis,0,sizeof(vis));
    Q.push({u,0});dis[u][u] = 0;
    while(!Q.empty()){
        node cur = Q.top();Q.pop();
        if(vis[cur.v]) continue;
        vis[cur.v] = 1;
        for(auto to : G[cur.v]){
            if(dis[u][to.v] > dis[u][cur.v] + to.w){
                dis[u][to.v] = dis[u][cur.v] + to.w;
                Q.push({to.v,dis[u][to.v]});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> id >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++) cin >> w[i];

    for(int i = 1;i <= n;i ++){
        int k;cin >> k;
        for(int j = 1;j <= k;j ++){
            int x,y;cin >> x >> y;
            //a[i].push_back(x);t[i].push_back(y);
            F[i].push_back({x + n,y});F[x + n].push_back({i,y});
        }
    }

    for(int i = 1;i <= m;i ++){
        for(int j = 0;j < F[i + n].size();j ++){
            for(int k = j + 1;k < F[i + n].size();k ++){
                node u = F[i + n][j],v = F[i + n][k];
                G[u.v].push_back({v.v,u.w + v.w});
                G[v.v].push_back({u.v,u.w + v.w});
                //cout << u.v << ' ' << v.v << ' ' << u.w + v.w << '\n';
            }
        }
    }

    for(int i = 1;i <= n;i ++){
        dijkstra(i);
    }
    
   // for(int i = 1;i <= n;i ++){
	//	for(int j = 1;j <= n;j ++){
			//cout << dis[i][j] << '\n';
	//	}
	//}

    while(q --){
        int x,y;cin >> x >> y;
        int ans = 1e18;
        for(int j = 0;j < F[x + n].size();j ++){
            for(int k = 0;k < F[y + n].size();k ++){
                node u = F[x + n][j],v = F[y + n][k];
                ans = min(ans,u.w + v.w + dis[u.v][v.v]);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }


    return 0;
}
