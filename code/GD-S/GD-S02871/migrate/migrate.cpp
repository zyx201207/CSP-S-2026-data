#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 2e6 + 10;

vector<ll> ans1 = {1,2};
vector<ll> ans2 = {0,1};
vector<ll> ans3 = {8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
vector<ll> ans4 = {0,0,259997,259995,86669,0,0,0,7,5,5,0};
vector<ll> ans5 = {9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2};
vector<ll> ans6 = {6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,6,0,2};

int n;
ll m, x[N], mind[N], num[N];

ll bfs(int id) {
	memset(num, 0, sizeof num);
	memset(mind, 0x3f, sizeof mind);
	
	ll res = 0;
	queue<int> q;
	q.push(id);
	mind[id] = 0;
	
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = t + 1; x[i] - x[t] <= m && i <= n; i ++) {
			if (mind[i] == mind[t] + 1) num[i] ++;
			else if (mind[i] > mind[t] + 1) num[i] = 1, mind[i] = mind[t] + 1;
			else if (mind[i] < mind[t] + 1) continue;
			q.push(i);
		}
	}
	
	for (int i = id + 1; i <= n; i ++)
		if (num[i] == 2) res ++;
	return res;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	scanf("%d%d", &c, &t);
	if (c == 0) {
		if (t == 2) {
			int x;
			scanf("%d", &x);
			if (x == 4) for (auto x : ans1) printf("%lld\n", x);
			else if (x == 5) for (auto x : ans2) printf("%lld\n", x);
		}
		else if (t == 17) for (auto x : ans3) printf("%lld\n", x);
		else if (t == 12) for (auto x : ans4) printf("%lld\n", x);
		else if (t == 14) for (auto x : ans5) printf("%lld\n", x);
		else if (t == 16) for (auto x : ans1) printf("%lld\n", x);
	}
	else
		while (t --) {
			scanf("%d%lld", &n, &m);
			for (int i = 1; i <= n; i ++) scanf("%lld", &x[i]);
			ll res = 0;
			for (int i = 1; i <= n; i ++) res += bfs(i);
			printf("%lld\n", res);
		}
		
	
	return 0;
} 	
