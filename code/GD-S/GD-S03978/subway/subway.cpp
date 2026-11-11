//#include <iostream>
//#include <queue>
//#include <vector>
//#define int long long
//using std::ios;
//using std::cin;
//using std::cout;
//using std::queue;
//using std::vector;
//using std::fill;

#include <bits/stdc++.h>
using namespace std;

const long long jarona = 2000000000000000000;

struct node {
	int p, q;
};

int c, n, m, d, q, x, y, w[500010], k[510], cnt[500010], o;
long long dis[500010];
bool b[500010];
vector<node> E[510], a[500010];

void B() {
	queue<int> q;
	fill(dis, dis + 1 + m, jarona);
	fill(b, b + 1 + m, 0);
	dis[x] = 0, b[x] = 1;
	q.push(x);
	while (q.size()) {
		int t = q.front(); q.pop();
//		cout << "t = " << t << "\n";
		b[t] = 0;
		for (node i : a[t]) {
			int id = i.p, num = i.q;	//线路编号 id，线路的第 num 站
//			cout << "Find the " << num << "th station in line " << id << "\n";
			num--;
			for (int j = 0; j < E[id].size(); j++) {
				if (j == num || (cnt[E[id][j].p] < 2 && E[id][j].p != y)) continue;
				int to = E[id][j].p;
//				cout << "To station " << to << "\tTime stamp added " << E[id][num].q << " + " << E[id][j].q << "\tNew Duration: " << dis[t] + E[id][num].q + E[id][j].q << "\n";
				if (dis[t] + E[id][num].q + E[id][j].q < dis[to]) {
					dis[to] = dis[t] + E[id][num].q + E[id][j].q;
					if (!b[to]) {
						b[to] = 1;
						q.push(to);
					}
				}
			}
		}
	}
//	for (int i = 1; i <= m; i++) cout << dis[i] << " "; cout << "\n";
	cout << dis[y] + w[x] + w[y] << "\n";
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> x >> y;
			cnt[x]++;
			a[x].push_back({i, j});
			E[i].push_back({x, y});
		}
	}
//	for (int i = 1; i <= m; i++) o += (cnt[i] >= 2);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= k[i]; j++) {
//			if (cnt[I[i][j].p] >= 2) E[i].push_back(I[i][j]);
//		}
//	}
//	cout << "o = " << o << "\n";
//	cout  << "Input cost : " << clock() << "\n";
	while (q--) {
//		if (cnt[y] == 1) E[a[y][0].p].push_back()
//		if (q <= 88000) break;
		cin >> x >> y;
		B();
	}
	return 0;
}

// {~}xiang ya{~} shi yi zhang yi kun nan jin cou de an jian shu ru wei zhu ti de di tu.
// zhong jian wang le 
// tong guan bu xu yao yong dao guo dong shuang tiao, ru guo ni zhi dao shen me shi guo dong shaung tiao de hua.

// ling bo wei bu yu ni
// zhua bu dao na zhi niao?
// ling yi ge ni ye bu bang mang- ta zui huai le
// jie shao-- ling bo wei bu!
// (zhong jian wang le)
// ling bo wei bu, kuai le de wu bu!

// ni zhe zhong qing kuang wo hai zhen mei jian guo, zhe yang ba, ni hou mian wang le
