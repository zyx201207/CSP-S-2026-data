#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], lst[N];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i] != a[i - 1]) lst[a[i - 1]] = i - 1;
	}
	lst[a[n]] = n;
	cout << lst[1];
	for(int i = 2; i <= m; i ++){
		cout << " " << lst[i] ;
	}
	return 0;
}

