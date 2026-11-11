#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 5;
int n, m, a[N], c[N], pre[N], ans, sum[N];
signed main(){
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout); 
	cin.tie(0) -> ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+1+n);
	for(int i=1;i<n;i++) c[i] = a[i+1] - a[i];
	for(int i=1;i<n;i++) pre[i] = pre[i-1] + c[i] * i, sum[i] = sum[i-1] + c[i];
	for(int i=1;i<n;i++){
		if(pre[i] > m) break;
		int l = i, r = n - 1, mx = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			int w = pre[mid] - pre[i-1] - (sum[mid] - sum[i-1]) * (i - 1);
//			cout<<i<<' '<<mid<<' '<<w<<'\n';
			if(w <= m){
				mx = mid;
				l = mid + 1;
			}else r = mid - 1;
		}
		ans = max(ans, mx - i + 2);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/

