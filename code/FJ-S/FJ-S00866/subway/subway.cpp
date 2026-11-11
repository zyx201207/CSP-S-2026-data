//#include <bits/stdc++.h>
//using namespace std;
//const int MAXN = 505;
//typedef pair < int, int > PII;
//int idx, m, n, d, q; // n是站数，m是线路数 
//int w[MAXN];
//int main() {
////	freopen("subway.in", "r", stdin);
////	freopen("subway.out", "w", stdout);
//	cin >> idx >> n >> m >> d >> q;
//	vector < PII > g[MAXN];
//	for(int i = 1; i <= m; i++) {
//		cin >> w[i];
//	}
//	for(int i = 1; i <= m; i++) {
//		int k, pre = 0; cin >> k;
//		for(int j = 1; j <= k; j++) {
//			int a, t;
//			cin >> a >> t;
//			g[pre].push_back({});
//		}
//	}
//	return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//struct Input {
//	int k;
//	vector < int > a;
//	vector < int > t;
//} input[500005];
//int idx, n, m, d, q;
//int g[1005][1005];
//bool flag[1005][1005];
//int w[1005];
//int main() {
//	cin >> idx >> n >> m >> d >> q;
//	for(int i = 1; i <= n; i++) {
//		cin >> w[i];
//	}
//	
//	for(int i = 1; i <= m; i++) {
//		cin >> input[i].k;
//		int a1, t1, a, t; 
//		cin >> a1 >> t1;
//		input[i].a.push_back(a1);
//		input[i].t.push_back(t1);
//		for(int j = 0; j < input[i].k; j++) {
//			cin >> a >> t;
//			input[i].a.push_back(a);
//			input[i].t.push_back(t);
//			flag[a1][a] = true;
//			a1 = a, t1 = t;
//		}
//	}
//	for(int i = 1; i <= m; i++) {
//		int a1, t1, a, t;
//		a1 = input[i].a[0];
//		t1 = input[i].t[0];
//		for(int j = 1; j < input[i].k; j++) {
//			a = input[i].a[j];
//			t = input[i].t[j];
//			for(int x = 1; x <= n; x++) {
//				if(x == a1 || x == a) continue;
//				if(flag[x][a1]) {
//					g[x][a] = w[x] + t1;
//				}
//			}
//			a1 = a, t1 = t;
//		}
//	}
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
int idx, n, m, d, q;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> idx >> m >> n >> d >> q;
	vector<vector<int> > g(n * m + 114, vector<int>(n * m + 114, 0x3f3f3f3f));
	vector<int> w(n + 1);
	int nn = n * m;
	for(int i = 1; i <= nn; i++) {
		g[i][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for(int i = 0; i < m; i++) {
		int k, a, t, a1; cin >> k;
		for(int j = 0; j < k; j++) {
			cin >> a >> t;
			for(int x = 0; x < m; x++) {
				if(x == i) continue;
				g[a + x * n][a + i * n] = t + w[a];
			}
			if(j != 0) {
				g[a1 + i * n][a + i * n] = 0;
			}
			a1 = a;
		}
	}
	for(int i = 1; i <= nn; i++) {
		for(int j = 1; j <= nn; j++) {
			for(int k = 1; k <= nn; k++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	while(q--) {
		int u, v, ans = 0x3f3f3f3f;
		cin >> u >> v;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < m; j++) {
				ans = min(ans, g[u + i * n][v + j * n]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
