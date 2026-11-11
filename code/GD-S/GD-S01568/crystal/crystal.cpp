#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 500050;
int n;
LL m, a[N], b[N];
int main () {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) 
		b[i] = b[i - 1] + a[i];
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		while ((a[i] * (i - cnt + 1) - (b[i] - b[cnt - 1]) <= m) && cnt > 0)  
			cnt--;
		ans = max(ans, i - cnt);
	}
	cout << ans;
	//fclose(stdin); 
	//fclose(stdout);
	return 0;
} 
