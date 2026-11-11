#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int a[N] = {};
int d[N] =  {};
int prefix[N] = {},pprefix[N] = {};
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;	

	for(int i = 1; i <= n;i ++ ) {
		cin >> a[i];
	}
	if(m == 0) {
		cout << 1 << '\n';
		return 0;
	}
	
	sort(a+1,a+n+1);
	
	for(int i = 2; i <= n;i ++ )  {
		d[i] = a[i] - a[i-1];
		pprefix[i] = pprefix[i-1] + d[i];
	}
	
	for(int i = 2; i <= n;i ++ ) {
		prefix[i] = prefix[i-1] + d[i]*(i-1);

	}
 	int ans = 0;
 	
 	for(int i = 1; i <= n;i ++ ) {
 		for(int j = 2; j < i;j ++ ) {
// 			cout << "i : " << i << " j : "  << j << " ans : " << (prefix[i]-prefix[j-1]-(j-1)*(pprefix[i]-pprefix[j-1])) << '\n';
		 }
	 }
	for(int i = 2; i <= n;i ++ ) {
		
		int l = 1,r = i,mid;
		int tot = 1;
		while(l <= r) {
			mid = (l+r) >> 1;
			if(prefix[i] - prefix[mid-1]-(mid-1)*(pprefix[i]-pprefix[mid-1]) > m) {
				l = mid+1;
			}else{
				tot = mid;
				r = mid-1;
			}
		}
		
		ans = max(ans,i-tot+1);
		
//		cout << "i : " << i << " tot : " << tot << " ans : " << ans << '\n';
	}
	
	cout << ans << '\n';

	return 0;
}

