#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500010];
int sum;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			long long num = 0, p = 0;
			for (int k = i; k < j; k++){
				num += a[j] - a[k];
				if (num > m){
					p = 1;
					break;
				}
			}
			if (p == 0){
				sum = max(sum, j-i+1);
			}
			else{
				break;
			}
		}
	}
	cout << sum;
	return 0;
} 
