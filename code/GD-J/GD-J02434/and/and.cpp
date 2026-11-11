#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 1;
int n, m;
int a[N];
int maxn = 0;
void dfs (int index, int cnt, int sum) {
	if (index >= n || cnt == m) {
		maxn = max(sum, maxn);
		return;
	}
	dfs(index + 1, cnt + 1, (sum & a[index]));
	dfs(index + 1, cnt, sum);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} 
	dfs(0, 0, 0);
	cout << maxn;
	return 0;
}
