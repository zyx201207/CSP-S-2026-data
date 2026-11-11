#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N], n, m;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			m = max(m, (a[i]&a[j]));
		}
	}
	cout << m;
	return 0;
} 
