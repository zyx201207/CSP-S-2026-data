#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in", "in", stdin);
	freopen("crystal.out", "out", stdout);
	long long n = 0, sum = 0;
	unsigned long long m1 = 0, m = 0;
	cin >> n >> m1;
	vector<long long> arr(n, 0);
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	long long ans = 0, cnt = 0;
	for(long long base = 1;base <= sum;base ++){
		cnt = 0; m = m1;
		vector<long long> cz(n, 0);
		for(int i = 0;i < n;i++){
			cz[i] = abs(arr[i] - base);
		}
		sort(cz.begin(),cz.end());
		for(int i = 0;i < n;i++){
			if(m < cz[i]) break;
			m -= cz[i];
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
