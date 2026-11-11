#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string n1 , m1;
	for(int i = 0 ; i <= 1 ; i++){
		n1 += s1[i];
		m1 += s2[i];
	}
	char n2 = s1[2] , m2 = s2[2];
	if(c1 == c2){
		cout << '1';
		if(n1 == m1){
			cout << '1';
			if(((n2 >= 'A' && n2 <= 'C') && (m2 >= 'A' && m2 <= 'C')) || ((n2 >= 'D' && n2 <= 'F') && (m2 >= 'D' && m2 <= 'F'))){
				cout << '1';
				if((n2 + 1 == m2 || n2 - 1 == m2)){
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
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
