#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
long long c11,c22,s11,s22,a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	c11 += (c1[0] - '0') *10;
	c11 += c1[1] - '0';
	c22 += (c2[0] - '0') *10;
	c22 += c2[1] - '0';
	s11 += (s1[0] - '0') *10;
	s11 += s1[1] - '0';
	s22 += (s2[0] - '0') *10;
	s22 += s2[1] - '0';
	if(c11 == c22){
		cout << 1;
		if(s11 == s22){
			cout << 1;//?
			if(s1[2] >= 'D' && s2[2] >= 'D'){
				cout << 1;
				if(abs(s1[2] - s2[2]) == 1 && s1[2] != 'D' && s1[2] != 'c' && s2[2] != 'D' && s2[2] != 'c'){
					cout << 1;
				}else{
					cout << "0";
				}
			}else if(s1[2] <= 'C' && s2[2] <= 'C'){
				cout << 1;
				if(abs(s1[2] - s2[2]) == 1 && s1[2] != 'D' && s1[2] != 'c' && s2[2] != 'D' && s2[2] != 'c'){
					cout << 1;
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
		
		
	}else{
		cout << "0000";
	}
	

	
	return 0;
} 
