#include<bits/stdc++.h>
using namespace std;
int a[2000007], tot = 0, tot1 = 0, bll[2000007], sj_[2000007], tot_ = 0;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, d;
		long long sum = 0;
		cin >> n >> d;
		sj_[0] = 1;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 2; i < n - 1; i++){
			if(a[i + 2] - a[i] <= d && a[i + 1] - a[i - 1] <= d && a[i + 2] - a[i - 1] > d){
				tot_++;
				sj_[tot_] = i;
			}
		}
		bll[1] = 1;
		tot = 0;
		for(int i = 2; i <= n + 1; i++){
			if(a[i] - a[i - 1] > d || i == n + 1){
				tot++;
				bll[tot + 1] = tot1 + 1;
				tot1 = i - 1;
			}
		}
		sj_[tot_ + 1] = n - 1;
		for(int i = 1, j = 2; i <= tot_; i++){
			while(bll[j + 1] <= sj_[i]){
				j++;
			}
			if(i == tot_){
				long long le = sj_[n] - max(sj_[n - 1], bll[j]), ri = min(n, bll[j + 1]) - sj_[n] - 1;
				sum += le * ri;
				break;
			}
			long long le = sj_[i] - max(sj_[i - 1], bll[j]), ri = min(sj_[i + 1] + 2, bll[j + 1]) - sj_[i] - 1;
			sum += le * ri;
		}
		cout << max(0LL, sum);
	}
	return 0;
}
