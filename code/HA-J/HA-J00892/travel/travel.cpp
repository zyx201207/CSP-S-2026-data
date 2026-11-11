#include <bits/stdc++.h>
using namespace std;
string c1, ls1, c2, ls2;
string l1, l2;
char s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> ls1 >> c2 >> ls2;
	l1 = ls1[0]+ls1[1];
	s1 = ls1[2];
	l2 = ls2[0]+ls2[1];
	s2 = ls2[2];
	bool side1, side2; // 0-->abc 1-->df
	if('A'<=s1&&s1<='C') side1 = 0;
	else side1 = 1;
	if('A'<=s2&&s2<='C') side2 = 0;
	else side2 = 1;
	if(c1 == c2){
		cout << "1";
		if(l1 == l2){
			cout << "1";
			if(side1 == side2){
				cout << "1";
				if(side1 == 0){
					if(abs((int)s1-(int)s2) == 1) cout << "1";
					else cout << "0";
				}
				else cout << "1";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
