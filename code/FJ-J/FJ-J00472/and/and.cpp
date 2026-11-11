#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 2e5 + 5, inf = 2147483647;
int n, m, a[maxn], xuan[maxn], ans;
void dfs(int id, int sum){
	if (id == m + 1){
		ans = max(ans, sum);
		return;
	}
	for (int i = xuan[id - 1] + 1; i <= n; i++){
		xuan[id] = i;
		dfs(id + 1, (sum & a[i]));
		xuan[id] = 0;
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 20){
		dfs(1, inf);
		cout << ans << endl;
	}
	else if (n <= 2000){
		if (m == 1){
			int maxx = -1;
			for (int i = 1; i <= n; i++)
				maxx = max(maxx, a[i]);
			cout << maxx;
		}
		else if (m == n){
			int sum = inf;
			for (int i = 1; i <= n; i++)
				sum = sum & a[i];
			cout << sum;
		}
		else if (m == 2){
			int maxx = -1;
			for (int i = 1; i <= n; i++)
				for (int j = i; j <= n; j++)
					maxx = max(maxx, (a[i] & a[j]));
			cout << maxx;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
