#include <bits/stdc++.h>
#define int long long
// It's not good that the computer can not input Chinese, but I think it's very good for me to finish the first problem in 15 minutes.
using namespace std;

const int N = 5e5+5;
int n,a[N],m,sum[N],ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i-1] + a[i];
	}
	for(int i = 1;i <= n;i++){
		int l = 1,r = i;
		while(l < r){
			int mid = ((l+r) >> 1);
			if((i - mid + 1) * a[i] - (sum[i] - sum[mid-1]) <= m) r = mid;
			else l = mid+1;
		}
		ans = max(ans,i - r + 1);
	}
	cout << ans;

	return 0;
}