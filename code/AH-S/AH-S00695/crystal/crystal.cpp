#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;

ll n, m, a[N];
ll p[N], sum;

bool check(int k){
	for(int i = 1; i <= n - k + 1; i ++){
		int j = i + k - 1;
		if(a[j] * k - (p[j] - p[i - 1]) <= m) return true;
	}
	return false;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i], sum += a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++)
		p[i] = p[i - 1] + a[i];
	int l = 1, r = n, ans = 0;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}

