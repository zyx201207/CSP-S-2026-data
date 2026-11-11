#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	cin >> n;
	long long m;
	cin >> m;
	long long a = -2e9;
	for (long long i = 1;i <= n;i++){
		long long t;
		cin >> t; 
		a = max(t,a);
	}cout << a;
	return 0;
} 
