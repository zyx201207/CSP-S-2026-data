#include <bits/stdc++.h>
using namespace std;
const int N = 200011;

int n, m, a [N], sum = 0;
vector <int> v;

inline void dfs(const int &x, const int &y){
	if (x == n + 1) {
		if (y == m) {
			int ans = v [0];
			for (int i = 1; i < y; i++)
				ans = ans & v [i];
			sum = max(sum, ans);	
		}
		return;
	}
	if (y < m)
		v.push_back(a [x]),
		dfs(x + 1, y + 1),
		v.pop_back();
	if (n - x + 2 + y > m)
		dfs(x + 1, y);
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a [i]);
	if (n <= 20 || (m != n && m != 1 && m != 2)) {
		dfs(1, 0);
		printf("%d", sum);
		return 0;
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++)
			sum = max(sum, a [i]);
		printf("%d", sum);
		return 0;
	}
	if (m == n) {
		sum = a [n];
		for (int i = 1; i < n; i++)
			sum = sum & a [i];
		printf("%d", sum);
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				sum = max(sum, a [i] & a [j]);
	printf("%d", sum);
	return 0;
}
