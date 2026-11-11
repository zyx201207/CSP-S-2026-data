#include <bits/stdc++.h>
using namespace std;

int j = 1;
int arr[20010];
int n, m;

int dfs(int i,int cnt, int j) {
	int o = 0;
	if(cnt == 0) o = arr[i];
	else o = arr[i] & cnt;
	if(i == 1 || i == n) return max(o,o&arr[1]);
	return max(dfs(i - 1, o, j + 1),dfs(i - 1, cnt, j));
}

int main() {
	freopen("and.in","r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 1);
	cout << dfs(n, 0, j);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
