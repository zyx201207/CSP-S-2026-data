#include <bits/stdc++.h>
using namespace std;

mt19937 myrand(time(0));

int main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c, t, n;
	cin >> c >> t >> n;
	while(t--)cout << myrand() % n << "\n";
	
	return 0;
}
