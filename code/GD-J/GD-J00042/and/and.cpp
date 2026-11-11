#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200005], x;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if (m == 1){
		sort(a + 1, a + n + 1);
		cout << a[n];
		return 0;
	}
	if (m == 2){
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				x = max(x, (a[i] & a[j]));
			}
		}
		cout << x;
		return 0;
	}
	if (m = n){
		x = a[1];
		for(int i = 2; i <= n; i++){
			x &= a[i];
		}
		cout << x;
		return 0;
	}
	cout << 7;
	return 0;
}
