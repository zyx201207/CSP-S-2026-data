#include<bits/stdc++.h>
using namespace std;
#define int long long

int ans = -1, n, m, a[500010], c[500010];

#define mid (l + r >> 1)

bool check(int x, int s){
	int cnt = 0;
	for(int i = x - 1; i > x - s; -- i){
		cnt += a[x] - a[i];
		if(cnt > m){
			return false;
		}
	}
	return true;
}

int fast(int l, int r, int x){
	while(l < r){
		if(check(x, mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++ i){
		c[i] = fast(1, i, i);
//		cout << c[i] << " " << i << "\n";
		ans = max(ans, c[i]);
//		if(ans == c[i])
//		cout << c[i] << "\n";
		if(i == n)
			break;
	}
	cout << ans;
}

