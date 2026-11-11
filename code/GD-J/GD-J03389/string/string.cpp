#include <bits/stdc++.h>
using namespace std;
char c[200005];
int n, a[200005];
long long ans = 0;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	for(int i = 1,j = n; i < j; i++,j--){
		if(a[i] == a[j]){
			if(c[i] != c[j]) ans += a[i];
		}
		else if(a[i] > a[j]){
			if(c[i] != c[j]) ans += a[j];
			a[i] -= a[j], --i;
		}
		else if(c[i] != c[j]) ans += a[i], a[j] -= a[i], ++j; 
	}
	cout << ans;
	
	return 0;
} 
