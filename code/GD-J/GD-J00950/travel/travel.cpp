#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string ss1, ss2;
	ss1 = s1[0] + s1[1];
	ss2 = s2[0] + s2[1];
	if(c1 == c2){
		cout << 1;
		if(ss1 == ss2){
			cout << 1;
			if((s2[2] == 'D' && s1[2] == 'F') || (s2[2] == 'F' && s1[2] == 'D') ){
				cout << "11";
			}
			else if((s2[2] == 'A' && s1[2] == 'B') || (s2[2] == 'B' && s1[2] == 'A')){
				cout << "11";
			}
			else if((s2[2] == 'C' && s1[2] == 'B') || (s2[2] == 'B' && s1[2] == 'C')){
				cout << "11";
			}
			else if((s2[2] == 'A' && s1[2] == 'C') || (s2[2] == 'C' && s1[2] == 'A')){
				cout << "10";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
