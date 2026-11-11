#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t, n;
long long ans, cnt, d, mn, a[N];
long long getmn(int l, int r){
	long long res = 1, lo = 0;
	for(int i = l + 1; i <= r; i++){
		if(a[i] - a[i-1] > d) return -1;
		lo += a[i] - a[i-1];
		if(lo > d){
			res++;
			lo = a[i] - a[i-1];
		}
	}
	return res;
}
void dfs(int id, int r, long long temp){
	if(temp > mn) return ;
	if(id == r){
		if(temp == mn) cnt++;
		return ;
	}
	long long aa = 0;
	for(int i = id + 1; i <= r; i++){
		aa += a[i] - a[i-1];
		if(aa <= d) dfs(i, r, temp + 1);
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> d;
		bool flag = true;
		scanf("%lld", &a[1]);
		for(int i = 2; i <= n; i++){
			scanf("%lld", &a[i]);
			if(a[i] - a[i-1] != a[2] - a[1]) flag = false;
		}
		if(flag){
			long long res = n - d - 1;
			if(res == 1) res = 0;
			if(res > 0) cout << res << '\n';
			else cout << 0 << '\n';
			continue;
		}
		for(int i = 1; i <= n - 3; i++){
			for(int j = i + 3; j <= n; j++){
				mn = getmn(i, j);
				if(mn == -1) break;
				cnt = 0;
				dfs(i, j, 0);
				if(cnt == 2) ans++;
				if(cnt > 2) break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
