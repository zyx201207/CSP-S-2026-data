#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum[5005][5005];//sum[i][j]表示从第1个数到第i个数中，每个数与第j个数的差的和 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	if (n > 5000){
		long long cha = a[2] - a[1],num = 0,t = 1;
		while (num <= m && t <= n){
			t++;
			num += cha * (t - 1);
		}
		cout << t - 1;
		return 0;
	}
	else{
		for (int j = 2; j <= n; j++){
			for (int i = 1; i <= j; i++) sum[i][j] = sum[i-1][j] + a[j] - a[i];
		}	
		for (int len = n; len >= 1; len--){
			for (int l = 1; l <= n - len + 1; l++){
				int r = l + len - 1;
				if (sum[r][r] - sum[l-1][r] <= m){
					cout << len;
					return 0;
				}
			}
		}
	} 
} 
