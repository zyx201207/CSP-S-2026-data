#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> sum(n + 1, 0);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i ++){
		sum[i + 1] = sum[i] + a[i];
	}
	int l = 0, r = 1;
	int max_ = 1;
	while(l < r && r < n){
		if(sum[r + 1] - sum[l] + m >= a[r] * (r - l + 1)){
			max_ = max(max_, r - l + 1);
			r ++;
		}else{
			l ++;
		}
	}
	cout << max_;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
