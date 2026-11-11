#include <bits/stdc++.h>
using namespace std;

int c, t, n, d, tmp;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	mt19937 rd(1145140);
	while(t--){
		cin >> n >> d;
		for(int i = 0; i< n; i++) cin >> tmp;
		cout << rd() % n << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
