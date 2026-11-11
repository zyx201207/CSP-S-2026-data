#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], sum[500005];
bool check(int mid){
	for(int i = 1; i + mid - 1 <= n; i++){
		//[i, i + mid - 1]
		int S = sum[i + mid - 1] - sum[i - 1];
		if((S + m) / mid >= a[i + mid - 1])	return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}	
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)	sum[i] = sum[i - 1] + a[i]; 
	int l = 1, r = n, ans;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans << endl;
	
	return 0;
}
