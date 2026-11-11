#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M = 500100;
int n , m , a[M] , s[M] , ans;

signed main(){
	freopen("crystal.in" , "r" , stdin) , freopen("crystal.out" , "w" , stdout);
	// freopen("data.in" , "r" , stdin) , freopen("data.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	cin>>n>>m;
	for(int i = 1; i <= n; ++i) cin>>a[i];
	sort(a + 1 , a + 1 + n);
	for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for(int i = 1 , j = 0; i <= n; ++i){
		while((i - j) * a[i] - (s[i] - s[j]) > m) ++j;
		ans = max(ans , i - j);
	}
	cout<<ans<<'\n';

	return 0;
}