#include <iostream>
using namespace std;
string c, s, ca, sa;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> ca >> sa;
	if (c == ca){
		cout << "1";
		if (s[0] == sa[0] && s[1] == sa[1]){
			cout << "1";
			if ((s[2] < 'D' && sa[2] < 'D') || (s[2] > 'C' && sa[2] > 'C')){
				cout << "1";
				if (int(s[2] - sa[2]) == 1 || int(sa[2] - s[2]) == 1){
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
} 
