#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n ;
int a[N], m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	
	int ans = 1,sum = 0;
	for(int i = 2,j = 1;i <= n;i++){
		if( a[i] != a[i-1] ) sum += (a[i] - a[i-1])*(i - j) ;
		while( sum > m && j <= i ){
			sum -= a[i] - a[j];
			++j;
		}
		ans = max( ans , i-j+1);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9
ans : 3
5 8
-3 -1 2 2 7
ans : 4
10 10
-2 3 4 -10 2 3 5 6 6 3
ans : 6
*/
