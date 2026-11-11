#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e5+10 , Inf = 0x7f7f7f7f;
LL n , m;
LL a[N] , sum[N];
LL ans;


signed main (){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout); 
	ans = 0;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a+1 , a+n+1);
	for(int i = 1 ; i <= n ; i++) sum[i] = sum[i-1] + a[i];
	for(int i = n ; i >= 1 ; i--){
		if(i < ans) break;
		LL l = 1 , r = i; 
		while(l <= r){
			int mid = l + r >> 1;
			if(1LL*(sum[i]-sum[mid-1]+m) >= 1LL*(i-mid+1)*a[i]) r = mid-1;
			else l = mid+1;
		}
		ans = max(ans , 1LL*(i-l+1));	
	}
	cout << ans;
	return 0;
} 
