#include <bits/stdc++.h>
using namespace std;
int a[511111], b[511111], c[511111] = {0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m, maxn = 0, sum = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++){
		b[i] = a[i] - a[i-1];
		b[1] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			c[j] = 0;
		}
		for(int j = n; j > n-i; j--){
			c[j] = 1;
		}
		long long ans = 0, anss = 0;
		do{
			sum = 1;
			for(int j = 1; j <= n; j++){
				if(c[j] == 1){
					ans += b[j+1] * sum;
					sum++;
					anss++;
				}
			}
			if(ans <= m){
				if(anss >= maxn){
					maxn = anss;
				}
			}
			ans = 0;
			anss = 0;
		}while(next_permutation(c+1, c+n+1));
	}
	if(maxn == 0){
		cout << 1;
		return 0;
	}
	cout << maxn;
	return 0;
}
