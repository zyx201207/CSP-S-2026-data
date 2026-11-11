#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e4 + 5;
int n,m,a[N];
int res,maxx;
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m ;
	for(int i = 1; i <= n ; i ++ )cin >> a[i];
	if(n == 1) {
		int ans = 0;
		for(int i = 1; i <= n; i ++ ) {
			ans = max(ans,a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
	   int ans = 0;
	   for(int i = 1; i <= n; i ++ ){
	   	for(int j = i + 1;j <= n; j ++ ){
	   		 ans = max((a[i] & a[j]),ans);
		   }
	   }
	   cout << ans;
	   return 0;
	}
	if(m == n){
		int res = a[1];
	   for(int i = 2; i <= n; i ++ )res = res & a[i];
	   cout << res;
	   return 0;
	}

	return 0;
}

