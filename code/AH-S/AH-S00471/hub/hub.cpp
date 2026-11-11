#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 300 + 10;

vector <int> G[N];
int n,k,t[N],vis[N];

void dfs1(int u){
    vis[u] = 1;
    for(int v : G[u]){
        if(t[v] && !vis[v]) dfs1(v);
    }
}

bool check(){
    for(int i = 1;i <= n;i ++) vis[i] = 0;
    int cnt = 0;
    for(int i = 1;i <= n;i ++){
        if(t[i] && !vis[i]){
            dfs1(i);cnt ++;
        }
    }//cout << cnt << 'a';
    return (cnt <= 2);
}

int ans = 1e18,dis[N];

void dfs2(int u,int fa){
	cout << u << ' ';
    vis[u] = 1;
    for(int v : G[u]){
		if(v == fa) continue;
        if(!vis[v]) dfs2(v,u);
        dis[u] = min(dis[u],dis[v] + 1);
    }
}

int q[N],l,r;

void calc(){
    l = 1,r = 0;
    for(int i = 1;i <= n;i ++){
        if(t[i]) dis[i] = 0,vis[i] = 1,q[++r] = i;
        else dis[i] = 1e18,vis[i] = 0;
    }
    int mx = 0;
    while(l <= r){
        int u = q[l++];
        for(int v : G[u]){
            if(!vis[v]){
                dis[v] = dis[u] + 1,mx = max(mx,dis[v]);vis[v] = 1;
                q[++r] = v;
            }
        }
    }
//for(int i = 1;i <= n;i ++) cout << dis[i] << ' ';cout << '\n';
	//cout << mx <<  '\n';
    ans = min(ans,mx);
}

void dfs(int step,int sum){
	if(sum > k) return;
    if(step == n + 1){
		if(sum < k) return;
        if(check()){
			//for(int i = 1;i <= n;i ++) cout << t[i] << ' ';cout << '\n';
            calc();
        }return;
    }
        t[step] = 1;dfs(step + 1,sum + 1);
        t[step] = 0;dfs(step + 1,sum);
  
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int id,T;cin >> id >> T;
    while(T --){
		
        cin >> n >> k;ans = 1e18;
        for(int i = 1;i <= n;i ++) G[i].clear();
        for(int i = 1;i < n;i ++){
            int u,v;cin >> u >> v;
            G[u].push_back(v);G[v].push_back(u);
        }
        dfs(1,0);
    cout << ans << '\n';
    }



    return 0;
}
