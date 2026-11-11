#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int fat[N];
int tq[N],dis[N];
vector<int>e[N];
int rt;
void dfs(int u,int fa) {
	fat[u] = fa;
	for (int v : e[u]) {
		if (v == fa) continue;
		dis[v] = dis[u] + 1; 
		if (dis[v] > dis[rt]) rt = v;
		dfs(v,u); 
	}
}

void dfs2(int u,int fa) {
	for (int v : e[u]) {
		if (v == fa) continue;
		tq[v] = min(tq[v],tq[u] + 1);
		dfs2(v,u);
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		for (int i=1;i<=n;i++) e[i].clear(),fat[i] = dis[i] = 0, tq[i] = 1e9;
		for (int i=1;i<n;i++) {
			int x,y;cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,1);
		int se = rt;
		for (int i=1;i<=n;i++) dis[i] = 0;
		dfs(rt,rt);
		int ed = rt;
//		cout << se << ' ' <<ed << endl;
		int x = ed,cnt=0,xx=1,yy=1;
		while (fat[x] != x) {
			if (cnt == dis[ed] / 3) xx = x;
			if (cnt == floor(dis[ed] * 2 / 3.0 + 0.5)) yy = x;
			cnt++;x = fat[x];
		}
//		cout << xx << ' ' << yy << endl;
		tq[xx]=0,tq[yy]=0;
		dfs2(xx,xx), dfs2(yy,yy);
		int ans = 0;
		
		for (int i=1;i<=n;i++) {
			ans = max(ans, tq[i]);
		}
		
		if (k == 2) {
			cout << ans << '\n';
		}
		else {
			cout << max(0,ans - (k-2) / 2) << '\n';
		}
	}
	return 0;
}
