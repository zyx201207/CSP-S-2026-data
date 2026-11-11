//GZ-S00112 遵义市新蒲新区滨湖中学 文玉成
#include <bits/stdc++.h>
using namespace std;
long long n, m, m1, a[500005], b[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	m1 = m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	int ans = 0;
	int cnt = 0;
	if (n > 5000){
		int k = a[1] - a[0];
		while(m-k>=0){
			m -= k;
			k += a[1]-a[0];
			ans++;
		}
		cout << ans+1 << endl;
		return 0;
	}
	for (int i = n-1; i >= 1; i--){
		m1 = m;
		cnt = 0;
		if (ans >= i) break;
		for (int j = i-1; j >= 0; j--){
			if(m1 - a[i] + a[j] >= 0){
				m1 = m1 - a[i] + a[j];
				cnt++;
			}else{
				break;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans+1 << endl;
	return 0;
}
