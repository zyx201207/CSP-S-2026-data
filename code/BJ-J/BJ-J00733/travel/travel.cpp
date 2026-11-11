#include<bits/stdc++.h>

using namespace std;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int rp = (s1[0] - '0') * 10 + s1[1] - '0';
	char rz = s1[2];
	int xp = (s2[0] - '0') * 10 + s2[1] - '0';
	char xz = s2[2];
	if(c1 == c2){
		s += '1';
		if(rp == xp){
			s += '1';
			if(rz + xz == 'A' + 'B' ||rz + xz == 'A' + 'C' ||rz + xz == 'B' + 'C' || rz +xz == 'D' + 'F'){
				s += '1';
				if(rz + xz == 'A' + 'B' ||rz + xz == 'B' + 'C' || rz +xz == 'D' + 'F'){
					s += '1';
				}else{
					s += '0';
				}
			}else{
				s += "00";
			}
		}else{
			s += "000";
		}
	
	}else{
		s += "0000";
	}
	
	cout << s;
	return 0;
}