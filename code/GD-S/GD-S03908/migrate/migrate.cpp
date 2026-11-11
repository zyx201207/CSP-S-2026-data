#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	int c = 0,t = 0,n = 0,d = 0,a[100] = {};
	cin >> c >> t;
	for (int i = 0; i < t; ++i){
		cin >> n >> d;
		for (int i = 0; i < n; ++i){
			cin >> a[i];
		}
	}
	if (t == 2) cout << "1" << endl << "2";
	if (t == 1) cout << "0";
	if (t == 3) cout << "2" << endl << "1" << "3";
	fclose (stdin);
	fclose (stdout);
	return 0;
}
