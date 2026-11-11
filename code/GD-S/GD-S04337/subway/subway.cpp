#include <bits/stdc++.h>
using namespace std;

struct STA{
	int num;
	vector<int> line;
};

int x, y;
int shortestime = INT_MAX;
int c, n, m, d, q;
vector<int> w;
vector<STA> sub;
vector<vector<int> > line;
vector<vector<int> > t;//t i j  i线到j站 

void dfs(int time, int nowsta, int nowline, vector<int> vis, bool first) { 
	if (nowsta == y) {
		time += t[nowline][nowsta] + w[nowsta];
		shortestime = min(shortestime, time);
		return;
	}
	for (int i = 0; i < (int)sub[nowsta].line.size(); i++) {//遍历经过它的线
		if (sub[nowsta].line[i] == nowline && first == false)
			continue;
		int newline = sub[nowsta].line[i];
		for (int j = 1; j < (int)line[newline].size(); j++) {//遍历线上的站 
			if (find(vis.begin(), vis.end(), line[sub[nowsta].line[i]][j]) == vis.end()) {
				vis.push_back(line[sub[nowsta].line[i]][j]);
				int newsta = line[sub[nowsta].line[i]][j];
				int newtime = t[nowline][nowsta];//去厅
				newtime += t[newline][nowsta];//去线
				if (first == 1 && newline == nowline)
					newtime = 0;
				
				dfs(time+newtime, newsta, newline, vis, 0);
				
				vis.pop_back();
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	w.resize(m+1);
	line.resize(n+1);
	sub.resize(m+1);
	t.resize(n+1);
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int ki;
		cin >> ki;
		t[i].resize(m+1);
		for (int j = 1; j <= ki; j++) {
			int stat;
			cin >> stat >> t[i][stat];
			line[i].push_back(stat);
			sub[stat].line.push_back(i);
		}
	}
	for (int i = 1; i <= q; i++) {
		shortestime = INT_MAX;
		cin >> x >> y;
		for (int j = 0; j < (int)sub[x].line.size(); j++) {
			vector<int> vis;
			vis.push_back(x);
			dfs(w[x]+t[sub[x].line[j]][x], x, sub[x].line[j], vis, 1);
		}
		cout << shortestime << '\n';
	}
	
	return 0;
}
