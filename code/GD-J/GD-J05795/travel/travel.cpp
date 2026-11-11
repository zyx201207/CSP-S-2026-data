#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >>s2;
	
	if (c1 == c2){
		cout << "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			
			int d1,d2;
			switch (s1[2]){
				case 'A':
					d1 = 0;
					break;
				case 'B':
					d1 = 1;
					break;
				case 'C':
					d1 = 2;
					break;
				case 'D':
					d1 = 3;
					break;
				case 'F':
					d1 = 4;
					break;
			}
			switch (s2[2]){
				case 'A':
					d2 = 0;
					break;
				case 'B':
					d2 = 1;
					break;
				case 'C':
					d2 = 2;
					break;
				case 'D':
					d2 = 3;
					break;
				case 'F':
					d2 = 4;
					break;
			}
			if ((d1 <= 2 && d2 <= 2)||(d1 >= 3 && d2 >= 3)){
				cout << "1";
				if (abs(d1 - d2) == 1){
					cout << "1" << endl;
				}else{
					cout << "0" << endl;
				}
			}else{
				cout << "00" << endl;
			}
		}else{
			cout << "000" << endl;
		}
	}else{
		cout << "0000" << endl;
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
