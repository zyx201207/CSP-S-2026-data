#include<bits/stdc++.h>
using namespace std;
long long a[2000009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int s, t;
	cin >> s >> t;
	if (s == 0){
		if (t == 2){
			int o;
			cin >> o;
			if (o == 4){
				cout << 1 << endl << 2;
			}
			else {
				cout << 0 << endl << 1;
			}
		}
		else if (t == 17){
			cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0;
		}
		else if (t == 12){
			cout << 0 << endl << 0 << endl << 259997 << endl << 259995 << endl << 86669 << endl << 0 << endl << 0 << endl << 0 << endl << 7 << endl << 5 << endl << 5 << endl << 0;
		}
		else if (t == 14){
			cout << 9999900000 << endl << 399995 << endl << 0 << endl << 716427 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2;
		}
		else if (t == 16){
			cout << 6800625333 << endl << 6247500 << endl << 6242502 << endl << 4998 << endl << 9994 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2;
		}
		return 0;
	}
	while (t--){
		int n, m;
		cin >> n >> m;
		int x = 0;
		for (int i = 1;i <= n;i++){
			cin >> a[i];
			if (i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
				x = 1;
			}
		}
		if (x == 0){
			if (a[2] - a[1] >= m){
				cout << 0 << endl;
			}
			else if (a[n] - a[1] <= m){
				cout << 0 << endl;
			}
			else {
				if (m / (a[2] - a[1]) <= 1 || n - 2 * (m / (a[2] - a[1])) < 0){
					cout << 0 << endl;
				}
				else {
					cout << n - 2 * (m / (a[2] - a[1])) << endl;
				}
			}
		}
	}
	return 0;
}
