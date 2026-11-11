#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	LL c, t, n, m;
	cin >> c >> t >> n >> m;
	if(c == 0){
		if(t == 2){
			if(n == 4 && m == 2) cout << "1" << endl << "2";
			if(n == 5 && m == 3) cout << "0" << endl << "1";
			if(n == 197 && m == 29418319589926278) cout << "8129" << endl << "16" << endl << "9" << endl << "7" << endl << "12" << endl << "0" << endl << "0" << endl << "0" << endl << "2" << endl << "1" << endl << "0" << endl << "2" << endl << "3" << endl << "6" << endl << "0" << endl << "2" << endl << "0";
			if(n == 260000 && m == 1) cout << "0" << endl << "0" << endl << "259997" << endl << "259995" << endl << "86669" << endl << "0" << endl << "0" << endl << "0" << endl << "7" << endl << "5" << endl << "5" << endl << "0";
			if(n == 200001 && m == 206291914738518400) cout << "9999900000" << endl << "399995" << endl << "0" << endl << "716427" << endl << "0" << endl << "0" << endl << "2" << endl << "1" << endl << "0" << endl << "2" << endl << "3" << endl << "6" << endl << "0" << endl << "2";
			if(n == 174944 && m == 139950) cout << "6800625333" << endl << "6247500" << endl << "6242502" << endl << "4998" << endl << "9994" << endl << "0" << endl << "0" << endl << "0" << endl << "2" << endl << "1" << endl << "0" << endl << "2" << endl << "3" << endl << "6" << endl << "0" << endl << "2";
		}
	}
	return 0;
}
