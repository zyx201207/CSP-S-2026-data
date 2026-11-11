#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2; 
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		cout << 1;
		int s11 = (int(s1[0])-48) * 10 + (int(s1[1])-48);
		int s22 = (int(s2[0])-48) * 10 + (int(s2[1])-48);
		if(s11 == s22){
			cout << 1;
			int z1 = int(s1[2]) - 65;
			int z2 = int(s2[2]) - 65;
			if((z1 <= 2 && z2 <= 2) || (z1 >= 3 && z2 >= 3)){
				cout << 1;
				if(((z1 <= 2 && z2 <= 2) && (abs(z1 - z2) == 1)) || (z1 >= 3 && z2 >= 3) && (abs(z1 - z2) == 1)){
					cout << 1;
				}else{
					cout << 0;
				}
			}else cout << "00";
		}else cout << "000";
	}
	else cout << "0000";
	
	return 0;
} 
