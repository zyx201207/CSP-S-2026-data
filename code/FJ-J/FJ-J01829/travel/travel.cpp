#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, l1, l2, l3, l4;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0; i < 2; i++){
		l1 += s1[i];
		l2 += s2[i];
	}
	l3 += s1[2];
	l4 += s2[2];
	if(c1 == c2){
		cout << 1;
		if(l1 == l2){
			cout << 1;
			if((l3[0]=='A'&&l4[0]=='B') || (l3[0]=='A'&&l4[0]=='C') || (l3[0]=='B'&&l4[0]=='C') || (l3[0]=='B'&&l4[0]=='A') || (l3[0]=='C'&&l4[0]=='A') || (l3[0]=='D'&&l4[0]=='E') || (l3[0]=='E'&&l4[0]=='D')){
				cout << 1;
				if((l3[0]=='A'&&l4[0]=='B') || (l3[0]=='B'&&l4[0]=='C') || (l3[0]=='D'&&l4[0]=='E') || (l3[0]=='B'&&l4[0]=='A') || (l3[0]=='C'&&l4[0]=='B') || (l3[0]=='E'&&l4[0]=='D')){
					cout << 1;
					return 0;
				}else{
					cout << 0;
					return 0;
				}
			}else{
				cout << "00";
				return 0;
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
		return 0;
	}
	return 0;
}
