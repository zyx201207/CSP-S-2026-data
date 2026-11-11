#include <bits/stdc++.h> 
using namespace std;
long long a[1000000000000000000];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, y;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < m - 1; i++){
		y = a[i] & a[i + 1];
	}
	cout << y;
	return 0;
}
