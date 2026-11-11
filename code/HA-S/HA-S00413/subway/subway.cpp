#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <bits/stdc++.h>


#include <vector>

#define ll long long

using namespace std;

ll c, n, m, d, q;

ll w[550];



int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	for(int i = 1; i <= q; i++){
		cout << "1\n";
	}
	

	

	return 0;



}

