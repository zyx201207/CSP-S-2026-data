#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in",'w',stdin());
	freopen("travel.out",'r',stdout());
	string s1,s2;
	char c1[5],c2[5];
	cin >> s1 >> c1 >> s2 >> c2;
	cout << (s1==s2);
	bool b1 = ((s1==s2)&&(c1[0]==c2[0]&&c1[1]==c2[1]));
	bool b2 = (c1[2]<='C'&&c2[2]<='C'),b3 = (c1[2]>'C'&&c2[2]>'C'),b4= abs(c1[2]-c2[2])==1;
	cout << b1;
	cout << b1&&(b2||b3);
	cout << b1&&b4;
	
	return 0;
}
