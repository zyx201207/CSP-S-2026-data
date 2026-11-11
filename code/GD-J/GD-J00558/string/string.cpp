#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n=1,m,cnt;
char a[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m;
	for(int i = 1; i <= m; i++){
		ll t;
		char c;
		cin >> t >> c;
		for(int j = n; j <= n+t-1; j++){
			a[j] = c;
		}
		n+=t;
	}
	n--;
	if(n % 2 == 0) {
		for(int i = n/2, j = n/2 + 1; i >= 1; i--,j++){
			if(a[i] != a[j]) cnt++;
		}
	} else {
		n = (n+1)/2;
		for(int i = n - 1, j = n + 1; i >= 1; i--,j++){
			if(a[i] != a[j]) cnt++;
		}
	}
	cout << cnt;
	return 0;
} 
