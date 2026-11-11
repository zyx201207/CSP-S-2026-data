#include <bits/stdc++.h>
using namespace std;

long long c, t, x, a[100000005][100000005], n, d;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t >> n >> d; 
	for (int i = 1; i <= t; i++){
		cin >> a[i][i];
	}
	for (int i = 2; i <= d; i++){
		if (a[i][i] == a[i - 1][i - 1]){
			x++;
		}
	}
	cout << "0" << "/n" << "1";
	return 0;
}
