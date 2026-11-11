#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 250005;
const int M = 1505;
const int INF = 1e9;
const int mod = 998244353;
int a[N], ra[N];
char c[N], rc[N];
void work(){
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	for(int i = 1; i <= n; i++){
		ra[i] = a[n - i + 1];
		rc[i] = c[n - i + 1];
	}
	int l = 0, r = 0, ans = 0;
	for(int idx = 0, idy = 0; l < sum / 2 || r < sum / 2;){
		if(l < r){
			idx ++;
			if(rc[idy] != c[idx]){
				ans += min(l + a[idx], r) - l;
			}
			l += a[idx];
		}else if(l > r){
			idy ++;
			if(rc[idy] != c[idx]){
				ans += min(r + ra[idy], l) - r;
			}
			r += ra[idy];
		}else{
			idy ++;
			idx ++;
			if(rc[idy] != c[idx]){
				ans += min(a[idx], ra[idy]);
			}
			r += ra[idy];
			l += a[idx];
		}
		l = min(l, sum / 2);
		r = min(r, sum / 2); 
//		cout << l << " " << r << " " << ans << "\n";
	}
	cout << ans;
	return ;
}
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t --){
		work();
	}
	return 0;
} 
/*
4
1 a
1 a
1 b
100 a
*/
//luogu uid:910628 球上神人共赏
