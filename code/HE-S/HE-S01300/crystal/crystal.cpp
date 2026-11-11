#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N] , b[N] , m;
int n;
map<int , int> mp;
bool check(int x){
	int sum = 0;
	for(int i = 1 ; i <= x ; i ++){
		sum += a[x] - a[i];
		if(sum > m) {
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	sort(a + 1 , a + 1 + n);
	if(n <= 5000){
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			int sum = 0 , mx = 0;
			for(int j = i ; j >= 1 ; j --){
				sum += (a[i] - a[j]);
				if(sum > m) break;
				mx ++;
			}
			ans = max(ans , mx);
		}
		cout << ans << "\n";
	}
	else{
		int l = 1 , r = n , ans = 0;
		while(l <= r){
			int mid = (l + r) / 2;
			if(check(mid)) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		cout << ans << "\n";
	}
	
	return 0;
} 
