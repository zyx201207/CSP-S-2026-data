#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn =  5e5+10;
int n,m,a[maxn],sum[maxn];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int l = 0,r = i,res = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if((mid-1)*a[i]-sum[i-1]+sum[i-mid] <= m){
				l = (res = mid) + 1;
			}else r = mid - 1;
		}ans = max(ans,res);
		sum[i] = sum[i-1]+a[i];
	}cout<<ans;
	return 0;
} 
