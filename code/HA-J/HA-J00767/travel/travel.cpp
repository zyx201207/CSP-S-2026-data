#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int a1[5], a2[5];
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(s1[2] == 'A') s1[2] = 1;
	if(s1[2] == 'B') s1[2] = 2;
	if(s1[2] == 'C') s1[2] = 3;
	if(s1[2] == 'D') s1[2] = 4;
	if(s1[2] == 'E') s1[2] = 5;
	
	if(s2[2] == 'A') s2[2] = 1;
	if(s2[2] == 'B') s2[2] = 2;
	if(s2[2] == 'C') s2[2] = 3;
	if(s2[2] == 'D') s2[2] = 4;
	if(s2[2] == 'E') s2[2] = 5;
	
	for(int i = 0; i <= 2; i ++) {
		a1[i] = s1[i];
		a2[i] = s2[i];
	} 
	
	if(c1 == c2) {
		cout << "1";
	} else {
		cout << "0";
	}
	
	if(c1 == c2 && a1[0] == a2[0] && a1[1] == a2[1]) {
		cout << "1";
	} else {
		cout << "0";
	}
	
	if(c1 == c2 && a1[0] == a2[0] && a1[1] == a2[1]) {
		if((a1[2] >= 1 && a1[2] <= 3 && a2[2] >= 1 && a2[2] <= 3) || (a1[2] >= 4 && a1[2] <= 5 && a2[2] >= 4 && a2[2] <= 5)) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
	}
     
    if(c1 == c2 && a1[0] == a2[0] && a1[1] == a2[1]) {
        if((a1[2] >= 1 && a1[2] <= 3 && a2[2] >= 1 && a2[2] <= 3) || (a1[2] >= 4 && a1[2] <= 5 && a2[2] >= 4 && a2[2] <= 5)) {
			if((a1[2]-a2[2] == 1) || (a2[2]-a1[2] == 1)) {
				cout << "1";
			} else {
				cout << "0";
			}
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
	}
    
	
	return 0;
}
