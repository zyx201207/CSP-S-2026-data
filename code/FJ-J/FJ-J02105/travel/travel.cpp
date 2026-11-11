#include <bits/stdc++.h>
using namespace std;
string c1,c2,r1,r2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> r1 >> r2;
	if (c1 == r1) {
		cout << 1;
		if (c2[0] == r2[0] && c2[1] == r2[1]){
			cout << 1;
			if ((c2[2] <= 'C' && r2[2] <= 'C') || (c2[2] >= 'D' && r2[2] >= 'D')){
				cout << 1;
				if (abs(r2[2] - c2[2] == 1)) cout << 1;
				else cout << 0;
			} else cout << "00";
		} else cout << "000";
	} else cout << "0000";
	return 0;
}
