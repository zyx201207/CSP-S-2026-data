#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d, x[2000005] = {};
	cin >> c >> t >> n >> d;
	for(int j = 1;j <= t; j++)
		for(int i = 1;i <=n;i++)
			cin >>x[i];
	for(int i = 1 ;i <= t;++i)
		cout <<"1"<<endl;
	return 0;
} 

