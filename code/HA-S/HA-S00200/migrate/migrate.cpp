#include<bits/stdc++.h>
using namespace std;
int c, t;
int n, d, x[2000005];
int num[100005], sum[100005], c[2000005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> d;
		num[i] = n;
		sum[i] = d;
		for (int j = 1; j <= n; j++){
			cin >> x[i];
			c[i] = x[i];
		}
	}
} 
