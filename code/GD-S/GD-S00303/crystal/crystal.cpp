#include<bits/stdc++.h> 
#define int long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;
const int N = 5e5 + 10; 
int n, m;
int a[N], pre[N];
int ans;
signed main(){
	fin("crystal.in");
	fout("crystal.out");
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for(int i = 1; i <= n; i++){
		int l = 1, r = i;
		while(l <= r){
			int mid = (l + r) / 2;
			if(a[i] * (i - mid) - (pre[i - 1] - pre[mid - 1]) <= m){
				r = mid - 1;
				ans = max(ans, i - mid + 1);
//				cout << mid << ' ' << i << '\n';
			}
			else l = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
//15:05 T1ÕâÃ´ÔõÃ´ÌÆ 
