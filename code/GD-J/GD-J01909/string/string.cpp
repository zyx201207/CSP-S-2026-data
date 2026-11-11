#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
int n, a[200005];
char c[200005];
int main(){
//	freopen("string6.in", "r", stdin);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	int x = 1, y = n;
	while(x < y){
		int minn = min(a[x], a[y]);
		if(c[x] != c[y]){	ans += minn;}
		a[x] -= minn;
		a[y] -= minn;
		if(a[x] == 0){	x++;}
		if(a[y] == 0){	y--;}
	}
	cout << ans;
	return 0;
}
