#include <bits/stdc++.h>
#define int long long
//#define double long double
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
using namespace std;
int C, n, m, d, q; //这输入格式看上去不太讲礼貌（雾）
int w[500010]; // 入站时间
struct node {
	int a; //站点 / 线路
	int t; //时间
};
vector<node> line[505]; //线路
vector<node> stop[500010]; //每个站点涉及的路线
int f[505][505]; //各站点间换乘（Floyed）
int k[505];
int x, y;
signed main() {
//	freopen("subway.out", "w", stdout); //诶我不小心把 freopen 注释了
	freopen("subway.in", "r", stdin);   //欸还没注释呢
//	freopen("subway.in", "r", stdin);   //欸我又不小心注释了
	freopen("subway.out", "w", stdout); //欸我骗你的 awa
	cin >> C >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][j] = 1000000000000000ll;
		}
		f[i][i] = 0;
	}
	for(int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &k[i]);
		for(int j = 1; j <= k[i]; j++) {
			scanf("%lld%lld", &x, &y);
			line[i].push_back(node {x, y});
			stop[x][i].t + y;
			for(auto st : stop[x]) {
//				y + st.t;
				f[i][st.a] = min(f[i][st.a], y + st.t);
				f[st.a][i] = f[i][st.a];
			}
			stop[x].push_back(node {i, y});
		}
	}
	for(int mid = 1; mid <= n; mid++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][mid] + f[mid][j]);
			}
		}
	}
	while(q--) {
		scanf("%lld%lld", &x, &y);
		int ans = 1000000000000000ll;
		for(auto s : stop[x]) {
			for(auto t : stop[y]) {
				ans = min(ans, f[s.a][t.a] + s.t + t.t + w[x] + w[y]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
