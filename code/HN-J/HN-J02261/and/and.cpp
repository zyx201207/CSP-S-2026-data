#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005];
int dfs(int m, int mm, int j){
	int ans = 0;
	if (m == 1){
		for (int i = j + 1; i <= n; i++)
			ans = max(ans, a[i] & mm);
		return ans;
	}
	for (int i = j + 1; i <= n; i++){
		ans = max(ans, a[i] & dfs(m - 1, mm & a[i], i));
	}
	return ans;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> n;
	cout << dfs(m, 1, 0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
