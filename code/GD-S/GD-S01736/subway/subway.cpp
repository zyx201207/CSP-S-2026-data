#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int c,n,m,d,q,w[N];
struct Node{
	int to,w;
};
vector <Node> edge[N];
int dfs(int now,int fa,int e){
	ll ans = 0;
	if(now > n)
		ans = w[now] + edge[now][1].w;
	for(auto x : edge[now]){
		int u = x.to;
		ll w = x.w;
		if(u == fa)
			continue;
		if(u == e)
			return ans;
		dfs(u,now,e);
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++){
		int sz;
		cin >> sz;
		for(int k = 1;k <= sz;k++){
			int u,w;
			cin >> u >> w;
			edge[i + n].push_back({u,w});
			edge[u].push_back({n + i,w});
		}
	}
	if(c == 0 || c >= 7 && c <= 11){
		for(int i = 1;i <= q;i++){
			int l,r;
			cin >> l >> r;
			cout << dfs(l,0,r) << endl;
		}
	}
	return 0;
}
