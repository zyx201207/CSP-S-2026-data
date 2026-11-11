#include <bits/stdc++.h>
using namespace std;

long long a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int e,t;
	cin >> e >> t;
	for(int i=1 ;i<=t; i++){
		long long n, d;
		cin >> n >>d;
		for(int j=1; j<=n; j++) 
			cin >>a[j];
		int c=abs(a[3]-a[2]);
		if(((d/c) >= 2) && ((n-(d/c-1)*c-1) > 0))
			cout << n-(d/c)*2+1;
		else 
			cout << 0;
		if(i!=t)
			cout <<'\n';
	}
	return 0;
}
