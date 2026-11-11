#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
long long n, m, arr[N], Max, num, ans, sum;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> arr[i];
		Max = max(Max, arr[i]);
		if(i == 1) num = arr[1];
		if(i >= 2) num &= arr[i];
	}
	if(m == 1) {
		cout << Max;
		return 0;
	}
	else if(m == n) {
		cout << num;
		return 0;
	}
	else if(m == 2) {
		for(int i = 1;i < n;i++) {
			for(int j = i + 1;j <= n;j++) ans = max(ans, arr[i] & arr[j]);
		}
		cout << ans;
		return 0;
	} 
	else if(m == n - 1) {
		for(int i = 2;i <= n;i++) {
			sum = arr[1];
			for(int j = 2;j <= n;j++) {
				if(j == i) continue;
				sum &= arr[j];
			}
			ans = max(ans, sum);
		}
		sum = arr[2];
		for(int i = 3;i <= n;i++) sum &= arr[i];
		ans = max(ans, sum);
		cout << ans;
		return 0;
	}
	return 0;
} 
