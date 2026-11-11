#include<bits/stdc++.h>
using namespace std;
long long a[100100], b[100100], c[100100];
long long ans, m, n;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	b[1] = a[1];
	c[1] = 0;
	for(int i = 2; i <= n; i++){
		b[i] = b[i-1] + a[i];
		c[i] = (i-1)*a[i]-b[i];
	}
	for(int i = 1; i <= n; i++){
		if(c[i] > m){
			ans = i-1;
			break;
		}
	}
	cout << ans;
	return 0;
}
