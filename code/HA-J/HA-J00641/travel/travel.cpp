#include <bits/stdc++.h>
using namespace std;
int c1,c2,d1,d2;
string s1,s2;
char x1,x2;
int to[305];
int data (string s) {
	int k = 0;
	for (int i = 0;i < s.length() && '0' <= s[i] && s[i] <= '9';i ++) {
		k *= 10;
		k += s[i] - '0';
	}
	return k;
}
int main () {
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1 = s1[s1.length() - 1];
	x2 = s2[s2.length() - 1];
	d1 = data(s1);
	d2 = data(s2);
	if (c1 != c2) {
		cout<<"0000";
		fclose (stdin);
		fclose (stdout);
		return 0;
	}
	if (d1 != d2) {
		cout<<"1000";
		fclose (stdin);
		fclose (stdout);
		return 0;
	}
	to['A'] = 0;
	to['B'] = 1;
	to['C'] = 2;
	to['D'] = 3;
	to['F'] = 4;
	if (!((x1 < 'D' && x2 < 'D') || (x1 > 'C' && x2 > 'C'))) {
		cout<<"1100";
		fclose (stdin);
		fclose (stdout);
		return 0;
	}
	int w = (to[x1] - to[x2] + 5) % 5;
	if (w != 1 && w != 4) {
		cout<<"1110";
		fclose (stdin);
		fclose (stdout);
		return 0;
	}
	cout<<"1111";
	fclose (stdin);
	fclose (stdout);
	return 0;	
}
