#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], t[500005], ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
		sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++){
//		cout << i << ":" << endl;
		memset(t, 0, sizeof(t));
		int sum = 0;
		int cnt = 0;
		for (int j = 1; j <= n; j++){
			t[j] = a[i] - a[j];
			if (t[j] >= 0){
				if (sum <= m - t[j]){
				cnt++;
				sum += t[j];
			}
			else{
				break;
			}
			}
//			cout << t[j] << " ";
		}
//		cout << endl << cnt << endl;
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
