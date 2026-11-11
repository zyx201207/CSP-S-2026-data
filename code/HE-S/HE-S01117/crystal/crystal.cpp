#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans = 1, a[500007];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, tot = 1, ans = 1;
	for(int r = 2;r <= n;++r){
		if(m >= tot * (a[r] - a[r - 1])){
			m -= tot * (a[r] - a[r - 1]);
			tot++;
			ans = max(ans, tot);
		}else{
			while(l < r && m < tot * (a[r] - a[r - 1])){
				m += a[r - 1] - a[l];
				l++;
				tot--;
			}
			if(l == r){
				continue;
			}else{
				m -= tot * (a[r] - a[r - 1]);
				tot++;
				ans = max(ans, tot);
			}
		}
	}
	cout << ans;
	return 0;
}
