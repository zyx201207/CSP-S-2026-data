#include<bits/stdc++.h>
using namespace std;
string s1, c1, s2, c2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> c1 >> s2 >> c2;
	if(s1 != s2){
		cout << "0000";
	}else{
		cout << '1';
		int x, y;
		x = (c1[0] - '0') * 10 + (c1[1] - '0'), y = (c2[0] - '0') * 10 + (c2[1] - '0');
		if(x != y){
			cout << "000";
		}else{
			cout << '1';
			bool ok = false;
			if((c1[2] == 'A' && (c2[2] == 'B' || c2[2] == 'C'))) ok = true;
			if((c1[2] == 'B' && (c2[2] == 'A' || c2[2] == 'C'))) ok = true;
			if((c1[2] == 'C' && (c2[2] == 'A' || c2[2] == 'B'))) ok = true;
			if(c1[2] == 'D' && c2[2] == 'F') ok = true;
			if(c1[2] == 'F' && c2[2] == 'D') ok = true;
			if(!ok){
				cout << "00";
			}else{
				cout << '1';
				ok = false;
				if(c1[2] == 'A' && c2[2] == 'B') ok = true;
				if((c1[2] == 'B' && (c2[2] == 'A' || c2[2] == 'C'))) ok = true;
				if((c1[2] == 'C' && c2[2] == 'B')) ok = true;
				if(c1[2] == 'D' && c2[2] == 'F') ok = true;
				if(c1[2] == 'F' && c2[2] == 'D') ok = true;
				cout << (ok ? '1' : '0');
			}
		}
	}
	return 0;
}
