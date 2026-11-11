#include<bits/stdc++.h>
using namespace std;
const int N = 1e9+10;
int a[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,ans=0; cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		a[i] &= a[i-1];
		ans = max(a[i], a[i-1]) ;
	}
	cout <<	ans;
	
	return 0;
} 
