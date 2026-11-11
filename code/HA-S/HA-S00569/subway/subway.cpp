#include <bits/stdc++.h>
using namespace std;
const int MAX_M = 2 * 1e5 + 3;
const int MAX_N = 500 + 3;
int c, n, m, d, z, k, x, y, w[MAX_M], tu[MAX_N][MAX_M];
long long cnt[MAX_N][MAX_M];
long long ans;
bool mk[MAX_N][MAX_M];
bool flag, flag2;
struct node {
	int line, gate, pd;
};
queue <node> q;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> c >> n >> m >> d >> z;
    for (int i = 1; i <= m; i++) {
    	cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int ai, t;
			cin >> ai >> t;
			tu[i][ai] = t;
		}
	}
	while(z--) {
		memset(mk, 0, sizeof(mk));
		memset(cnt, 0, sizeof(cnt));
		flag2 = 0;
		flag = 0;
		while (q.size()) {
			q.pop();
		}
		cin >> x >> y;
		ans = 0;
		if (x == y) {
			cout << "0" << endl;
			continue;
		}
		ans += w[x];
		ans += w[y];
		for (int i = 1; i <= n; i++) {
			if (tu[i][x]) {
				cnt[i][x] += tu[i][x];
				mk[i][x] = 1;
				node data;
				data.line = i, data.gate = x;
				data.pd = 0;
				q.push(data);
			}
			if (tu[i][x] && tu[i][y]) {
				flag2 = 1;
			}
		}
		if (flag2) {
			cout << ans << endl;
			continue;
		}
		while (!q.empty()) {
			node tmp = q.front();
			flag = 0;
			q.pop();
			int nl = tmp.line, ng = tmp.gate;
			int npd = tmp.pd;
			if (ng == y) {
				ans += cnt[nl][ng];
				if (npd == 1)
				    ans += tu[nl][ng];
				break;
			}
			for (int i = 1; i <= m; i++) {
				if (tu[nl][i] && !mk[nl][i]) {
					mk[nl][i] = 1;
					cnt[nl][i] += cnt[nl][ng];
					node data;
					if (i == y) {
						ans += cnt[nl][i];
						if (npd == 1) {
							ans += tu[nl][i];
						}
						flag = 1;
						break;
					}
					if (npd == 0) {
						cnt[nl][i] += tu[nl][i];
						data.pd = 1;
					} else {
						data.pd = 0;
					}
					data.line = nl, data.gate = i;
					q.push(data);
				}
			}
			for (int i = 1; i <= n; i++) {
				if (tu[i][ng] && !mk[i][ng]) {
					mk[i][ng] = 1;
					node data;
					cnt += tu[nl][ng];
					if (npd == 1) {
					    cnt[i][ng] += tu[i][ng];
					}
					data.line = i, data.gate = ng;
					data.pd = 0;
					q.push(data);
				}
			}
			if (flag) {
				break;
			}
		}
        cout << ans << endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

