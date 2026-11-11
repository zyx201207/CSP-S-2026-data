#include <bits/stdc++.h>
using namespace std;
#define int long long

int read() {
	int aa = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch=='-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		aa = (aa<<3) + (aa<<1) + (ch^48);
		ch = getchar();
	}
	return aa*f;
}

const int N = 5e5+10;
struct node {
	int to, w;
};
int c, n, m, d, q;
int w[520];
int f[520][520];
vector<node> e[N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), m = read(), n = read(), d = read(), q = read();
	for(int i = 1;i<=n;i++) {
		w[i] = read();
//		e[i].reserve(2*d+10);
	}
	memset(f, 0x3f, sizeof f);
	for(int i = 1;i<=m;i++) {
		f[i][i] = 0;
		int k = read();
		for(int j = 1;j<=k;j++) {
			int a = read(), t = read();
			e[a].push_back({i, t});
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 0;j<e[i].size();j++) {
			for(int k = 0;k<e[i].size();k++) {
				if(i==j)
					continue;
				int u = e[i][j].to, v = e[i][k].to;
				f[u][v] = min(f[u][v], e[i][j].w+e[i][k].w);
			}
		}
	}
	for(int k = 1;k<=m;k++)
		for(int i = 1;i<=m;i++)
			for(int j = 1;j<=m;j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	
	while(q--) {
		int x = read(), y = read();
		int mn = 1e9;
		for(int i = 0;i<e[x].size();i++)
			for(int j = 0;j<e[y].size();j++)
				mn = min(mn, e[x][i].w+e[y][j].w + f[e[x][i].to][e[y][j].to]);
		cout<<mn + w[x] + w[y]<<"\n";
	}
	return 0;
}
