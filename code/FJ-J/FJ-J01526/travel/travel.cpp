#include <bits/stdc++.h>
using namespace std;

string Ca,Cb;
string Sa,Sb;

int main () {
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> Ca >> Sa >> Cb >> Sb;
	
	int a = Ca[0] * 10 + Ca[1];
	int b = Cb[0] * 10 + Cb[1];
	
	if (a != b) {
		cout << "0000";
		return 0;
	}
	
	int la = Sa[0] * 10 + Sa[1];
	int lb = Sb[0] * 10 + Sb[1];
	
	if (la != lb) {
		cout << "1000";
		return 0;
	}
	
	int na = Sa[2] - 'A';
	int nb = Sb[2] - 'A';
	
	if (abs(na - nb) > 2 && (na <= 2 && nb <= 2 || na > 2 && nb > 2)) {
		cout << "1100";
		return 0;
	}
	
	if (abs(na - nb) != 1) {
		cout << "1110";
		return 0;
	}
	
	cout << "1111";
	
	return 0;
} 
