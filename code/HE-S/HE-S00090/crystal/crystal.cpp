#include <iostream>
#include <algorithm> 
using namespace std;
long long a[500010], sum[500010];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long m;
	cin >> n >> m;
	int maxi = 1;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
		int l = 1, r = i;
		while (l < r){
			int mid = l + r + 1 >> 1;
			if (mid * a[i] - (sum[i] - sum[i - mid]) <= m)l = mid;
			else r = mid - 1;
		}
		maxi = (maxi > l ? maxi : l);
	}
	cout << maxi;
	return 0;
} 
