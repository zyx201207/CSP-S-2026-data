#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 250;
long long a[N], p[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	sort(a + 1, a + n + 1);
	if(a[1] > 0){
		for(int i = 1; i <= n; i++){
			p[i] = p[i - 1] + a[i];
		}
		long long sum = 0;
		for(int i = 0, j = 2; i <= j, j <= n; ){
			int l = j - i;
			int k = l;
			k *= a[j];
			int g = p[j] - p[i];
			k -= g;
			if(k <= m){
				if(sum < l){
					sum = l;
				}
				j++;
			}else{
				i++;
			}
		}
		cout << sum;
	}else{
		long long q = a[1];
		q = abs(q);
		q += 1;
		for(int i = 1; i <= n; i++){
			a[i] += q;
		}
		for(int i = 1; i <= n; i++){
			p[i] = p[i - 1] + a[i];
		}
		long long sum = 0;
		for(int i = 0, j = 2; i <= j, j <= n; ){
			int l = j - i;
			int k = l;
			k *= a[j];
			int g = p[j] - p[i];
			k -= g;
			if(k <= m){
				if(sum < l){
					sum = l;
				}
				j++;
			}else{
				i++;
			}
		}
		cout << sum;
	}
	return 0;
}
