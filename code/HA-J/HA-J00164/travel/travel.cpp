#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string se1,se2;

bool match(string sc,string sd) {
	if (((se1==sc)&&(se2==sd))||((se1==sd)&&(se2==sc))) {
		return true;
	}
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string r1 = s1.substr(0,2);
	se1 = s1.substr(2,1);
	string r2 = s2.substr(0,2);
	se2 = s2.substr(2,1);
	bool a=0,b=0,c=0,d=0;
	if (c1==c2) {
		a=1;
		if(r1==r2) {
			b=1;
			if (match("A","B")||match("B","C")||match("E","F")) {
				c=1;
				d=1;
			}
			if (match("A","C")) {
				c=1;
			}
		}
	}
	cout << a << b << c << d;
	return 0;
}
