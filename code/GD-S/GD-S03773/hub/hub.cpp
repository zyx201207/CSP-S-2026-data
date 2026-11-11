#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n,k,a[N];
bool c[N];
vector<int> e[N];
int dfs(int u,int fa,int dep){
	if(c[u]) return dep;
	int mi = 1e9;
	for(auto v:e[u]){
		if(v == fa) continue;
		mi = min(mi,dfs(v,u,dep+1));
	}
	return mi;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin >> C >> T;
	while(T--){
		int mi = 1e9;
		cin >> n >> k;
		for(int i = 1,u,v;i < n;i++){
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i = 0;i < (1<<n);i++){
			int x = i,j = 1,cnt = 0,mx = 0;
			memset(c,0,sizeof(c));
			while(x){
				if(x&1) cnt++;
				c[j++] = (x&1);
				x >>= 1;
			}
			if(cnt != k) continue;
			for(int j = 1;j <= n;j++) mx = max(mx,dfs(j,0,0));
			mi = min(mi,mx);
		}
		for(int i = 1;i <= n;i++) e[i].clear(), c[i] = 0;
		cout << mi << "\n";
	}
	return 0;
} 
