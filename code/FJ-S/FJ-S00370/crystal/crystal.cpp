#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N] , n , m;
int s[N];
bool check(int mid){
	for(int i = 1 ; i <= n ; i ++){ 
		int st = i - mid + 1; 
		if(st <= 0) continue;
		int sum = a[i] * mid - (s[i] - s[st - 1]);
		if(sum <= m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	s[0] = 0;
	for(int i = 1 ; i <= n ; i ++) s[i] = s[i - 1] + a[i];
	int l = 0 , r = 1e7;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1; 
	}
	cout << l << '\n';
	return 0;
}
