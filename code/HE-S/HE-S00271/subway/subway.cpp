#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+10;
int c,n,m,d,q,res,cnt = 0;
int w[1145],vis[1145],k[1145];
vector<int> a[509];
vector<int> t[555];
vector<int> pt[N];
void dfs(int cur,int obr,int cst,int sub) {
	if(cur == obr) {
		res = min(res,cst);
		return;
	}
	for(int i = 0;i < pt[cur].size();i++) {
		int u = pt[cur][i];
		for(int j = 0;j < a[u].size();j++) {
			if(!vis[a[u][j]]) {
				vis[a[u][j]] = 1;
				dfs(a[u][j],obr,cst+t[u][cur]+t[u][a[u][j]],u);
				vis[a[u][j]] = 0;
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++) {
		cin >> k[i];
		for(int j = 1;j <= k[i];j++) {
			int x,y;
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
			pt[a[i][j]].push_back(i);
		}
	}
	while(q--) {
		memset(vis,0,sizeof(vis));
		int l,r;
		res = INT_MAX;
		cin >> l >> r;
		vis[l] = 1;
		for(int i = 0;i < pt[l].size();i++) dfs(l,r,t[pt[l][i]][l],pt[l][i]);
		cout << w[l]+res+w[r] << '\n';
	}
	return 0;
}
