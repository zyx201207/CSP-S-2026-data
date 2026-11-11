#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int M = 3e5 + 5;

int a[N];
int cnt[M];
deque<int> dq;
unordered_map<int, bool> inQ;

int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		dq.clear();
		inQ.clear();
		for (int j = i; j <= n; j++) {
			if (inQ[a[j]]) {
				while(dq.size() && dq.back() != a[j]) {
					inQ[dq.back()] = false;
					dq.pop_back();
				}
				continue;
			}
			dq.push_back(a[j]);
			inQ[a[j]] = true;
		}
		while (dq.size()) {
			cnt[dq.front()]++;
			dq.pop_front();
		}
	}

	for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
	return 0;
}

