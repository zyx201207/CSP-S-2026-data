#include <bits/stdc++.h>
using namespace std;

int n, m, x, max1 = INT_MIN;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> x;
		max1 = max(max1, x);
	}
	cout << max1;
	
	return 0;
}
