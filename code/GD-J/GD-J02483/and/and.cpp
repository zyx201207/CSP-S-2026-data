#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long m, n, a[2005];
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long sum, maxn = -1e9;
	if(m == 1){
		for(int i = 1; i <= n; i++){
			sum = (a[i]&n);
			maxn = max(maxn, sum);
		}
	}
	if(m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				sum = (a[i]&a[j]&n);
				maxn = max(maxn, sum);
			}
		}
	}
	cout << maxn;

	return 0;
}
