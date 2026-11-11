#include <bits/stdc++.h>
using namespace std;
const int N = 1314;
const int M = 520;
int n, k, sz[N], dep[N], ans;
vector<int> g[N];
bool in[N];
int df(int u,int fa,int d){
	if(in[u]) return d;
	int res = 1e9;
	for(int x:g[u]){
		if(x ^ fa){
			res = min(res,df(x,u,d+1));
		}
	}return res;
}
int dfs(int u,int fa,int d){
	dep[u] = dep[fa]+1;
	if(!in[u]) d = max(d,df(u,0,0));
	else sz[u]=1;
	int res = d;
	for(int x:g[u]){
		if(x != fa){
			res = max(res,dfs(x,u,d));
			if(sz[x]&&sz[u]){
				sz[u]+=sz[x]; sz[x]=0;
			}
		}
	}
	return res;
}
void dfss(int p,int now){
	if(now==k) {
		for(int i=1;i<=n;i++) sz[i]=0;
		int res = dfs(1,0,0);
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(sz[i]) cnt++;
		}
		if(cnt <= 2) ans = min(ans,res);
		return ;
	}
	for(int i=p+1;i<=n&&now+(n-i+1)>=k;i++){
		in[i]=true; dfss(i,now+1); in[i]=false;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, T; cin >> c >> T;
	while(T--){
		ans = 1e9;
		cin >> n >> k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int x, y; cin >> x >> y;
			g[x].push_back(y); g[y].push_back(x);
		}
		dfss(0,0);
		cout << ans << '\n';
	}
	return 0;
}
