#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[100001], sum, max1 = -1, max2 = -1;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		sum = sum & a[i];
		max1 = max(max1, a[i]);
	}
	if (n == m){
		cout << sum;
	}
	else if (m == 1){
		cout << max1; 
	}
	else if (m == 2){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				if (j == i){
					continue;
				}
				max2 = max(max2, a[i] & a[j]);
			}
		}
		cout << max2;
	}else{
		cout << a[n];
	}
	return 0;
}
