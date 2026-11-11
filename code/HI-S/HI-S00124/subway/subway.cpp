#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define int long long
int read() {
	int x=0,f=1;char chr=getchar();
	while (chr<'0'||'9'<chr){if(chr=='-')f=-f;chr=getchar();}
	while ('0'<=chr&&chr<='9'){x=x*10+chr-'0';chr=getchar();}
	return x*f;
}
const int N = 510,M = 5e5 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int f[N][N];
struct Node {
	int a,t;
	Node(int _a,int _t) : a(_a),t(_t) {}
};
vector<Node> v[N];
vector<Node> st[M]; // 每一个站点经过的线路 
int w[M];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	for (int i = 1; i <= m; i++) {
		w[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		int k = read();
		while (k--) {
			int a = read(),t = read();
			v[i].push_back(Node(a,t));
			st[a].push_back(Node(i,t));
		}
	}
	memset(f,0x3f,sizeof(f));
	for (int i = 1; i <= n; i++) {
		f[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (auto x : st[i]) {
			for (auto y : st[i]) {
				f[x.a][y.a] = min(f[x.a][y.a],x.t + y.t);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
//	cout << "f = \n";
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << f[i][j] << " \n"[j == n];
//		}
//	}
	for (int i = 1; i <= q; i++) {
		int x = read(),y = read();
		int ans = inf;
		for (auto j : st[x]) {
			for (auto k : st[y]) {
				ans = min(ans,w[x] + j.t + f[j.a][k.a] + k.t + w[y]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
