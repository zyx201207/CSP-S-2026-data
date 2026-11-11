#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 5e5 + 10;
long long a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m, s = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int c = a[1] - a[0];
	int sh = 0;
	for(int i = 0; i < n - 1; i++){
		s += i * c;
		if(m < s){
			s -= i * c;
			break;
		}
		sh++;
	}
	if(sh <= n - 1)cout << sh;
	else cout << n;
	return 0;
} 
