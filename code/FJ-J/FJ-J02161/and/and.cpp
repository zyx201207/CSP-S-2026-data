#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, m;
long long a[N], b[N], c[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	long long q = -1e9;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		q = max(q, a[i]);
	}
	if(m == 1){
		cout << q;f
		return 0;
	}
	b[1] = a[1];
	for(int i = 2; i <= n; i++){
		b[i] = a[i] & b[i - 1];
	}
	if(m == n){
		cout << b[n];
		return 0;
	}
	long long w = -1e9;
	for(int i = 1; i <= n - m; i++){
		c[i] = a[i];
		for(int j = i + 1; j <= i + m; j++){
			c[i] &= a[j];
		}
		w = max(w, c[i]);
	}
	cout << w;
	return 0;
}
