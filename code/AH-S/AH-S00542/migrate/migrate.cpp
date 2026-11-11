#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long c, t, n, x, a[N];
int main(){
	freopen("migrate.in","r", stdin);
	freopen("migrate.out","w", stdout);
	cin>> c>> t;
	while(t --){
		cin>> n>> x;
		for(int i = 1; i <= n; i ++){
			cin>> a[i];
		} 
		long long ans = 0;
		for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++){
				if((a[j] - a[i]) % x != 0 && (a[j] - a[i]) / x >= 1){
					ans ++;
				}
			}
		}
		cout<< ans<< "\n";
	}
	return 0;
} 

