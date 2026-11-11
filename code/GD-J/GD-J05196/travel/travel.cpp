#include <bits/stdc++.h>
using namespace std;
string c1, c2;
string s1, s2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	int a=0, b=0, ac=0, d=0;
	
	if (c1 == c2) a = 1;
	
	
	string rc,xc;
	rc = s1[0]+s1[1];
	xc = s2[0]+s2[1];
	if (rc == xc) b = 1&&a;
	
	
	rc = s1[2];
	xc = s2[2];
	string l[] = {"A", "B", "C"};
	string r[] = {"D","F"};
	int c, x;
	for (int i=0;i<3;i++){
		if (rc == l[i]) c = 1;
		if (xc == l[i]) x = 1;
	}
	for (int i=0;i<2;i++){
		if (rc == r[i])c = 0;
		if (xc == r[i])x = 0;
	}
	if (c == x) ac = 1&&b;
	
	if (ac == 1){
		if (c==0) d=1;
		else if ((rc=="A"&&xc=="B") || (rc=="B"&&xc=="A")||(rc=="C"&&xc=="B") || (rc=="B"&&xc=="C")) d = 1;
	}
	
	cout << a << b << ac << d;
	
	
	return 0;
}
