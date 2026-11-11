#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define ll long long
#define path vector<int>
using namespace std;

int c, t;
ll n, d, ans;
ll a[2000001];
vector<path> v[2000001];

ll run(int start) {
	path p0 = {start};
	ll sum = 0;
	v[start].push_back(p0);
	for (int i=start+1; i<=n; i++) {
		ll canFly = a[i] - d;
		int minSize = 20000010;
		for (int j=start; j<=i-1; j++) {
			if (a[j] >= canFly) {
				for (path p : v[j]) {
					path newp = p;
					newp.push_back(i);
					v[i].push_back(newp);
					minSize = min(minSize, (int)newp.size());
				}
			}
		}
		for (int j=0; j<(int)v[i].size(); j++) {
			path p = v[i][j];
			if ((int)p.size() > minSize) {
				v[i].erase(v[i].begin() + j);
				j--;
			}
		}
		if (v[i].size() == 2)
			sum ++;
	}
	return sum;
}
void printPath(path p) {
	bool flag = false;
	for (int i : p) {
		if (flag) {
			cout << ",";
		}
		cout << i;
		flag = true;
	}
	cout << "\n";
}
void printTest() {
	cout << "\n";
	for (int i=1; i<=n; i++) {
		printf("[%d]%lld \n", i, a[i]);
		for (path p : v[i]) {
			printPath(p);
		}
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d %d", &c, &t);
	bool flag = false;
	while (t--) {
		scanf("%lld %lld", &n, &d);
		for (int i=1; i<=n; i++) {
			scanf("%lld", &a[i]);
		}
		for (int i=1; i<n; i++) {
			if (flag) {
				for (int i=1; i<=n; i++) {
					v[i].clear();
				}
			}
			ans += run(i);
			flag = true;
			//printTest();
		}
		printf("%lld\n", ans);
		ans = 0;
	}
	return 0;
}

