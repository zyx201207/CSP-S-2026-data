#include<bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], sum[500005];
bool check(int k){
	for(int i = k;i <= n;i++){
		long long t = k * a[i] - sum[i] + sum[i - k];
		if(t <= m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << "\n";
	return 0;
} 
