#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool b1, b2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << '1';
		if(s1.substr(0, 2) == s2.substr(0, 2)){
			cout << '1';
			if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') || (s1[2] == 'D' || s1[2] == 'E') && (s1[2] == 'D' || s1[2] == 'E')){
				cout << '1';
				if(abs(int(s1[2]) - int(s2[2])) == 1){
					cout << '1';
				}
				else{
					cout << '0';
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
	cout << '\n';
	return 0;
}
