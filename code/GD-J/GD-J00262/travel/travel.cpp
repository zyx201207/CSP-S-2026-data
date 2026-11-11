#include <bits/stdc++.h>
using namespace std;

string c, cc, s, ss;
char ed1, ed2;
bool f = 1;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> cc >> s >> ss;
	if (c == s){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}

	if (cc[0] == ss[0] && cc[1] == ss[1]){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	ed1 = cc[2], ed2 = ss[2];
	if (ed1 == 'A' || ed1 == 'B' || ed1 == 'C'){
		if (ed2 == 'A' || ed2 == 'B' || ed2 == 'C'){
			cout << "1";	
		}else{
			cout << "00";
			return 0;
		}
	}else{
		if (ed2 == 'D' || ed2 == 'F'){
			cout << "1";
			f = 0;
		}else{
			cout << "00";
			return 0;
		}
	}
	if (f){
		if (ed1 == 'A'){
			if (ed2 == 'B'){
				cout << "1";
			}else{
				cout << "0";
			}
		}else if (ed1 == 'B'){
			if (ed2 == 'B' || ed2 == 'C'){
				cout << "1";
			}else{
				cout << "0";
			}
		}else{
			if (ed2 == 'B'){
				cout << "1";
			}else{
				cout << "0";
			}
		}
	}else{
		cout << "1";
	}
	return 0;
}
