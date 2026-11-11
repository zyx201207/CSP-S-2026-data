#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long 
bool _;
int a[N] , s[N];
int n , m , p[N] , ans , mark[N]; 
int cnt[10];
bool __;
void dfs(int x , int last) {
	if (x == m + 1) {
		int sum = p[1];
		for (int i = 2 ; i <= m ; i ++) sum &= p[i];
		ans = max(ans , sum);
		return ;
	}
	for (int i = last + 1 ; i <= n ; i ++) {
		if (!mark[i]) {
			mark[i] = 1;
			p[x] = a[i];
			dfs(x + 1 , i);
			mark[i] = 0;
		}
	}
}
bool cmp(int x , int y) {
	return x > y;
}
signed main() {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	//cout << (&_ - &__) * 1.0 / 1024.0 / 1024.0 << " ";
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	map <int , bool> mp;
	int mul = 1;
	for (int i = 0 ; i <= 30 ; i ++) {
		mp[mul - 1] = 1;
		mul *= 2;
	}
	cin >> n >> m;
	int fl1 = 1 , fl2 = 1;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i];
		if (!mp.count(a[i])) fl1 = 0;
		if (a[i] >= 4) fl2 = 0;
	}
	if (fl1) {
		sort(a + 1 , a + 1 + n , cmp);
		int sum = a[1];
		for (int i = 2 ; i <= m ; i ++) sum &= a[i];
		cout << sum;
		return 0;
	}
	if (fl2) {
		for (int i = 1 ; i <= n ; i ++) cnt[a[i]] ++;
		if (cnt[3] >= m) cout << 3;
		else if (cnt[3] + cnt[2] >= m) cout << 2;
		else if (cnt[3] + cnt[1] >= m) cout << 1;
		else cout << 0;
		cout << '\n';
		return 0;
	}
	if (m == n) {
		int sum = a[1];
		for (int i = 2 ; i <= n ; i ++) sum &= a[i];
		cout << sum << "\n";
		return 0;
	}
	dfs(1 , 0);
	cout << ans;
	return 0;
} 
/*
5 3
3 0 1 2 0

65pts?
*/
