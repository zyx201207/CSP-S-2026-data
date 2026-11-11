#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, ans;
int a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int i = 1;
	while(i < n){
		int mi = INT_MAX;
		for(int j = 1, k = j + i;j <= n - i;j++, k++){
			ans = 0;
			for(int q = j;q <= k;q++){
				ans += a[k] - a[q];
			}
			mi = min(mi, ans);
		}
		if(mi <= m){
			i++;
		}else{
			cout << i;
			return 0;
		}
	}
	return 0;
}
