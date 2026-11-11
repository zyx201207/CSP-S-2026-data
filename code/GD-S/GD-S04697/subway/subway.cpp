#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int c, n, m, d, q, minn;
int st[50005];
struct line {
	int size;
	int io_time[50005];
	int io_station[50005];
} l[505];
vector<int> stl[50005];
vector<int> iostl[50005];
int vis[50005];
queue<int> sta;
queue<int> step;
void bfs(int s, int e) {
	minn = 999999;
	while(!sta.empty()) {
		sta.pop();
		step.pop();
	}
	memset(vis, -1, sizeof(vis));
	vis[s] = 0;
	for(int i = 0; i < stl[s].size(); i++) {
		for(int j = 1; j <= l[stl[s][i]].size; j++) {
			if(l[stl[s][i]].io_station[j] == s) {
				continue;
			}
			sta.push(l[stl[s][i]].io_station[j]);
			step.push(st[s] + st[e] + iostl[s][i] + l[stl[s][i]].io_time[j]);
			vis[l[stl[s][i]].io_station[j]] = st[s] + st[e] + iostl[s][i] + l[stl[s][i]].io_time[j];
		}
	}
	while(!sta.empty()) {
		if(vis[sta.front()] != -1 && vis[sta.front()] > step.front()) {
			sta.pop();
			step.pop();
			continue;
		}
		if(sta.front() == e) {
			minn = min(step.front(), minn);
			sta.pop();
			step.pop();
			continue;
		}
		for(int i = 0; i < stl[sta.front()].size(); i++) {
			for(int j = 1; j <= l[stl[sta.front()][i]].size; j++) {
				if(vis[l[stl[sta.front()][i]].io_station[j]] != -1 && vis[l[stl[sta.front()][i]].io_station[j]] < step.front() + l[stl[sta.front()][i]].io_time[j] + iostl[sta.front()][i]) {
					continue;
				}
				sta.push(l[stl[sta.front()][i]].io_station[j]);
				step.push(step.front() + l[stl[sta.front()][i]].io_time[j] + iostl[sta.front()][i]);
				vis[l[stl[sta.front()][i]].io_station[j]] = step.front() + l[stl[sta.front()][i]].io_time[j] + iostl[sta.front()][i];
			}
		}
		sta.pop();
		step.pop();
	}
	return;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &st[i]);
	}
	for(int i = 1; i <= n; i++) {
		cin >> l[i].size;
		for(int j = 1; j <= l[i].size; j++) {
			cin >> l[i].io_station[j] >> l[i].io_time[j];
			stl[l[i].io_station[j]].push_back(i);
			iostl[l[i].io_station[j]].push_back(l[i].io_time[j]);
		}
	}
	for(int i = 1; i <= q; i++) {
		int s, e;
		cin >> s >> e;
		bfs(s, e);
		cout << minn << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
