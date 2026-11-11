#include<bits/stdc++.h>
using namespace std;
long long n, a[200005], k = 1, alll = 0;
string c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	if (n == 1){
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		alll += a[i];
		if (c[i] != c[1]){
			k = 0;
		}
	}
	if (k){
		cout << 0;
		return 0;
	}
	cout << (alll - alll % 2) / 2;
	return 0;
}
