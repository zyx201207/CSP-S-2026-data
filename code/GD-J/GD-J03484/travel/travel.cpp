#include<bits/stdc++.h>
using namespace std;
int i,j,a1,a2,c1,c2; 
string s1,s2;
char b1,b2; 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a1 = int(s1[0])*10 + int(s1[1]);
	a2 = int(s2[0])*10 + int(s2[1]);
	b1 = s1[2];
	b2 = s2[2];
	if(c1 == c2){
		cout << "1";
		if(a1 == a2){
			cout << "1";
			if((b1 <= 'C' && b2 <= 'C') || (b1 >= 'D' && b2 >= 'D')){
				cout << "1";
				if((b1+1 == b2) || (b2+1 == b1)){
					cout << "1";
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
