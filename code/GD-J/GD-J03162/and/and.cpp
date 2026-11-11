#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[1000001];
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a, a+n);
	cout << a[2];
	
	return 0;
} 
