#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

ll n, m;
ll a[N];
ll ans;
ll sum[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int cnt = a[1];
	for (int i = 1; i <= n; i++){
		a[i] -= cnt;
//		sum[i] = 
		for (int j = 1; j < i; j++){
			sum[i] += a[i] - a[j];
		}
//				cout << sum[i] << " " << endl;
	}
	//	cout << endl;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int j = upper_bound(sum + 1,sum + 1 + n,sum[i] + m) - sum;
		if (sum[j] - sum[i] <= m){
			ans = max(j - i + 1,ans);
		}else {
			j--;
			ans = max(j - i+ 1,ans);
		}
//		for (int j = n; j >= i; j--){
//			if (sum[j] - sum[i] <= m){
////				cout << sum[i] << " " << sum[j] << " ";
//				cout << j - i + 1;
//				return 0;
//			}
//		}
	}
	cout << ans;
	return 0;
}

