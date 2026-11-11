#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}	
	int d = a[1];
	for(int i = 1; i <= n; i++){
		d &= a[i];
	}
	if(m == 1) cout << m;
	if(m == n) cout << d;
	
	return 0;
}
