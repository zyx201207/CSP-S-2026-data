#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, mid, sum, m, ans;
const int N = 5e5 + 10;
int a[N];
signed am(){
	int ans = 0;
	double ave = sum / n;
	for (int i = n;i >= 1;i--){
		if (a[i] >= ave){
			ans = i;
		}else{
			break;
		}
	}
	return ans;
}
signed jsum(){
	int ans = 0;
	for (int i = 1;i <= n;i++){
		if (a[i] == a[mid]){
			ans++;
		}
	}
	return ans;
}
void solve1(){
	mid = am();
	
	int i = mid;
	while(true){
		if (a[i] + 1 <= a[mid] && m){
			a[i]++;
			m--;
		}else{
			i--;
			ans++;
		}
		if (i < 1 || m <= 0){
			break;
		}
	}
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		sum += a[i];
	}
	solve1();
	
	cout << ans;
	return 0;
}
