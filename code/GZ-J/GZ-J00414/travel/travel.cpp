// GZ_J00414 张苇然 实验三中 
#include <bits/stdc++.h>
#define ll long long
#define vll vector <ll>
#define pll pair <ll,ll>
using namespace std;

int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3) {
		cout << "1";
		if (s2.substr(0,2) == s4.substr(0,2)) {
			cout << "1";
			if ((s2[2] >= 'A' && s2[2] <= 'C' && s4[2] >= 'A' && s4[2] <= 'C') || (s2[2] >= 'D' && s2[2] <= 'F' && s4[2] >= 'D' && s4[2] <= 'F' && s2[2] != 'E' && s4[2] != 'E')) {
				cout << "1";
				if (abs(s2[2] - s4[2]) == 1) cout << "1";
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
