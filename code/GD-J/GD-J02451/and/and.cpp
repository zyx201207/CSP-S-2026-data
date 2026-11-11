#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 250;
int a[N], b[N], c[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		long long k = a[i];
		for(int j = i; j <= i + m - 1; j++){
			k &= a[j];
		}
		if(sum < k){
			sum = k;
		}
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		b[i] = a[n - i + 1];
	}
	long long num = 0;
	for(int o = 1; o <= n; o++){
		long long k;
		for(int j = o; j <= o + m - 1; j++){
			if(j != o){
				k = k & b[j];
			}else{
				k = b[j];
			}
		}
		if(num < k){
			num = k;
		}
	}
	if(sum > num){
		cout << sum;
	}else{
		cout << num;
	}
	return 0;
}
