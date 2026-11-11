#include<bits/stdc++.h>
using namespace std;
string c1r, s1r, c2x, s2x;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1r >> s1r >> c2x >> s2x;
	if(c1r == c2x){
		cout << 1;
		if((s1r[0] == s2x[0]) && (s1r[1] == s2x[1])){
			cout << 1;
			if((s1r[2] <= 'C' && s2x[2] <= 'C') || (s1r[2] >= 'D' && s2x[2] >= 'D')){
				cout << 1;
				int tempr = (s1r[2] - 'A'), tempx = (s2x[2] - 'A');
				if(abs(tempr - tempx) == 1){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
				return 0;
			}
		}else{
			cout << "000";
			return 0;
		}
	}else{
		cout << "0000";
		return 0;
	}
	return 0;
}
