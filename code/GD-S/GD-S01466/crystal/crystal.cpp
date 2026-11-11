#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n, m, a[500005];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int c = 0, i = n, j = n - 1, ans = 1;
	while(j > 0){
		c += a[i] - a[j];
		while(c > m){
			c -= (i - j) * (a[i] - a[i - 1]);
			i--;
		}
		if((i - j + 1) > ans) ans = i - j + 1;
		j--;
	}
	cout << ans << endl;
	return 0;
}
