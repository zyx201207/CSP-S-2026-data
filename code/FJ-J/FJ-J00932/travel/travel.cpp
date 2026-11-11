#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool a, b;
int main (){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << "1";
		for (int i = 0; i < 3; ++ i){
			if (s1[i] >= '0' && s1[i] <= '9' && s2[i] >= '0' && s2[i] <= '9'){
				if (s1[i] == s2[i]){
					a = true;
				}
				else {
					a = false;
				}
			}
			else {
				if (a == false){
					cout << "000";
					return 0;
				}
				cout << 1;
				if((s1[i] == 'A' && s2[i] == 'C') || (s1[i] == 'C' && s2[i] == 'A')){
					cout << "10";
				}
				else if ((s1[i] == 'A' && s2[i] == 'B') || (s1[i] == 'B' && s2[i] == 'C') || (s1[i] == 'D' && s2[i] == 'F') || (s1[i] == 'F' && s2[i] == 'D')){
					cout << "11";
				}
				else cout << "00";
			}
		}
	}
	else {
		cout << "0000";
		return 0;
	}
	return 0; 
} 
