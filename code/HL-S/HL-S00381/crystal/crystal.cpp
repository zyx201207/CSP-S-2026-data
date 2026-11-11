#include <bits/stdc++.h>
using namespace std;
long long int n,m,a[500001],man[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (long long int i = 1; i <= n; i++){
		cin >> a[i];
		
	}
	for (long long int i = 1; i <= n; i++){
		for (long long int j = 1; j <= n-1; j++){
			if (a[j] > a[j+1]){
				long long int l = a[j];
				a[j] = a[j+1];
				a[j+1] = l;
			}
		}
	}
	for (long long int i = n; i >= 2; i--){
		long long int cnt = a[i],x = 1;
		bool b = 1;
		for (long long int j = i-1; j >= 1; j--){
			long long int c = m;
			if (cnt - a[j] <= c){
				x++;
				c = c - (cnt - a[j]);
			}else{
				b = 0;
			}
			if (b){
				j = -1;
			}
		}
		man[i] = x;
	}
	int max = -1;
	for (long long int i = 1; i <= n; i++){
		if (man[i] > max){
			max = man[i];
		}
	}
	cout << max;
	return 0;
} 
