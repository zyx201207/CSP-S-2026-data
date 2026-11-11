#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out", "w",stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char c11, c12, c21, c22,s11, s12, s13, s21, s22, s23;
	c11 = c1[0]; c12 = c1[1];
	c21 = c2[0]; c22 = c2[1];
	s11 = s1[0]; s12 = s1[1]; s13 = s1[2];
	s21 = s2[0]; s22 = s2[1]; s23 = s2[2];
	if (c11 == c21 && c12 == c22){
		cout << 1;
		if (s11 == s21 && s12 == s22){
			cout << 1;
			if (((s13 == 'A' || s13 == 'B' || s13 == 'C') && (s23 != 'D' && s23 != 'F')) || (s13 == 'D'|| s13 == 'F') && (s23 == 'D' || s23 == 'F')){
				cout << 1;
				if (s23 == s13 + 1 || s23 == s13 - 1){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << "00";
				return 0;
			}
		}
		else{
			cout << "000";
			return 0;
		}
	}
	else{
		cout << "0000";
		return 0;
	}
	
	return 0;
}