#include<bits/stdc++.h>
using namespace std;

struct Node{
	long long v,t;
};

int c,n,m,d,q,x,y;
long long ans = 1e18 + 10;
const int M = 5e5+10,N = 510,K = 1e5 + 10;
int w[M];
bool vis[M];
long long a[N][K];
long long t[N][K];
vector<Node> G[M]; 

void dfs(int u,int fa,long long sum){
	
	if(u == y){
		ans = min(ans,sum + 1ll*(w[x] + w[y]));
		return;
	}
	if(vis[u]) return;
	for(auto i : G[u]){
		if(i.v == fa) continue;
		vis[u] = 1;
		dfs(i.v,u,sum + i.t);
		vis[u] = 0;
	}
}

int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 2;j <= k;j ++){
			for(int l = 1;l <= j - 1;l ++){
				long long T = t[i][j] + t[i][j - l];
				G[a[i][j - l]].push_back({a[i][j],T});
				G[a[i][j]].push_back({a[i][j - l],T});
			}
		}
	}
	
	for(int i = 1;i <= q;i ++){
		cin >> x >> y;
		ans = 1e18 + 10;
		dfs(x,-1,0);
		cout << ans << '\n';
	}

	return 0;
}

