#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
char m1,m2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int a = s1[1]+s1[2];
	int b = s2[1]+s2[2];
	m1 = s1[2];
	m2 = s2[2];
	if(c1 == c2){
		cout << "1";
		if (a != b) {
			cout << "1";
			if (abs(m1-m2) <= 2){
				cout << "1";
				if (abs(m1-m2) <= 1){
					cout << "1";
				}
				else cout <<"0";
			}
			else cout <<"00";
	}
	    else cout << "000";
	}
	else cout << "0000"; 
	return 0;
} 
