#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m;
const int maxn = 6e5 + 10;
int a[maxn] , sum[maxn];
bool check(int d){
	int min1 = 1e18;
	for(int i = d ; i <= n ; i++){
		int s = (d - 1) * a[i] - (sum[i - 1] - sum[i - d]);
//		cout <<  i << ' ' << (d - 1) * a[i] << ' ' << s << '\n';
		min1 = min(s , min1);
	}
	return min1 <= m;
}
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	for(int i = 1 ; i <= n ; i++){
		sum[i] = sum[i - 1] + a[i];
//		cout << a[i] << ' ';
	}
//	for(int i = 1 ; i <= n ; i++){
//		cout << sum[i - 1] - sum[i - 3] << ' ';
//	}
//	cout << endl;
	int l = 1 , r = n;
	while(l <= r){
		int mid = (l + r) / 2;
//		cout << mid << '\n';
		if(check(mid)){
			l = mid + 1;
		}
		else r = mid - 1;
//		cout << endl;
	}
	cout << r;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
