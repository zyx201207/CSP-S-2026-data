#include<bits/stdc++.h>
using namespace std;
string c, s, cc, ss;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> cc >> ss;
	if(c == cc){
		cout << 1;
		if(s[0] == ss[0] && s[1] == ss[1]){
			cout << 1;
			if((s[2] <= 'C' && ss[2] <= 'C') || (s[2] >= 'D' && ss[2] >= 'D')){
				cout << 1;
				if(abs(s[2] - ss[2]) == 1){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
