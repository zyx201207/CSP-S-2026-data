#include <bits/stdc++.h>
using namespace std;

#define int long long

int c1, c2;
string s1, s2;
int p1, p2, p3, p4;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2) {
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]) {
			cout<<"1";
			int side1, side2;
			side1 = side2 = 1;
			if(s1[2]=='D' || s1[2]=='E')
				side1 = 2;
			if(s2[2]=='D' || s2[2]=='E')
				side2 = 2;
			if(side1==side2) {
				cout<<"1";
				int sit1 = s1[2]-'A', sit2 = s2[2]-'A';
				if(abs(sit1-sit2)==1)
					cout<<"1";
				else
					cout<<"0";
			}
			else
				cout<<"00";
		} else
			cout<<"000";
	} else
		cout<<"0000";
	
	return 0;
}
