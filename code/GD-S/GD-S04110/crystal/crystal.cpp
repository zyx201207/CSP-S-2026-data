#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, ans = 0, cnt = 0, l = 2, r = 2, now = 1;
int a[N], s[N];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	if(n == 1){
		cout << 1;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++){
		s[i] = a[i] - a[i - 1];
	}
	cnt = s[2], ans = 1;
	while(r <= n){
		if(cnt >= m){
			l++, now--;
			cnt -= a[r] - a[l - 1];
			if(l > r){
				r = l = r+1,now = 1;
				cnt = 0;
				continue;
			}
		}
		ans = max(ans, now);
		r++;
		if(r > n) break;
		now ++;
		cnt += s[r] * (now - 1);
	}
	ans = max(ans, now);
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
