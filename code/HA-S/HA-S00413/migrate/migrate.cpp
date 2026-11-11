#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <bits/stdc++.h>


using namespace std;

long long c, t;

const long long maxn = 2e6 + 10;

long long ans = 0;


int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> c >> t;
	
	while (t--){
		
		long long n, d;
		cin >> n >> d;
		
		long long a[n + 10];
		for(long long i = 1; i <= n; i++) {
			cin >> a[i];
			
		}
		n -= d;
		n -= d;
		
		if(n <= 0){
			cout << "0\n";
		}
		else {
			cout << n << '\n';
		}
	}
	

	return 0;



}

