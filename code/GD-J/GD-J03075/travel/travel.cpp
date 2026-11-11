#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int x, y;
	string sf, ss;
	cin >> x >> sf >> y >> ss;
	int lf = (sf[0] - '0') * 10 + sf[1] - '0', ls = (ss[0] - '0') * 10 + ss[1] - '0';
	if(x == y){
		cout << 1;
		if(lf == ls){
			cout << 1;
			if((sf[2] >= 'A' && sf[2] <= 'C' && ss[2] >= 'A' && ss[2] <= 'C') || (sf[2] >= 'D' && sf[2] <= 'E' && ss[2] >= 'D' && ss[2] <= 'E')){
				cout << 1;
				if((sf[2] == 'A' && ss[2] == 'B') || (sf[2] == 'B' && ss[2] == 'A') || (sf[2] == 'B' && ss[2] == 'C') || (sf[2] == 'C' && ss[2] == 'B') || (sf[2] == 'D' && ss[2] == 'E') || (sf[2] == 'E' && ss[2] == 'D')){
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
