#include <iostream>
#include <queue>
using namespace std;

long long helper(vector<long long> nums, long long d) {
	int n = nums.size();
	vector<vector<int>> g(n);
	int p = 0;
	for (int i = 1; i < n; i++) {
		while (nums[i] - nums[p] > d) p++;
		for (int j = p; j < i; j++) {
			g[j].push_back(i);
		}
	}
	long long res = 0;
	for (int s = 0; s < n; s++) {
		vector<int> visited(n, 0);
		visited[s] = 1;
		vector<int> d(n, 0);
		deque<pair<int, int>> q;
		q.emplace_back(1, s);
		while(!q.empty()) {
			int a = q[0].second, b = q[0].first;
			q.pop_front();
			for (int next : g[a]) {
				if (d[next] && d[next] <= b) continue;
				//cout << "[" << next << "] ";
				if (!visited[next]) {
					q.emplace_back(b + 1, next);
				}
				d[next] = b + 1;
				visited[next] += visited[a];
			}
		}
		for (int x : visited) res += (x == 2);
		//cout << s << " res: " << res << endl;
	}
	return res;
}

void sol() {
	int n;
	long long d;
	cin >> n >> d;
	vector<long long> x(n);
	for (long long& y : x) cin >> y;
	int p = 0;
	long long res = 0;
	for (int i = 1; i < n; i++) {
		if (x[i] - x[i - 1] <= d) continue;
		res += helper(vector<long long>(x.begin() + p, x.begin() + i), d);
		p = i;
	}
	cout << res + helper(vector<long long>(x.begin() + p, x.end()), d) << endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c, t;
	cin >> c >> t;
	while (t--) {
		sol();
	}
	return 0;
}
