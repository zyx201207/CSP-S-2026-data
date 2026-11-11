#include<bits/stdc++.h>
using namespace std;

char c1[30], s1[30], c2[30], s2[30];

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x=s1[2]-'A'+1, y=s2[2]-'A'+1;
	if (c1[0]==c2[0] && c1[1]==c2[1]) {
		if (s1[0]==s2[0] && s1[1]==s2[1]) {
			if ((x<=3 && y<=3) || (x>=4 && y>=4)) {
				if (abs(x-y)==1)
					cout<<"1111";
				else
					cout<<"1110";
			}
			else
				cout<<"1100";
		}
		else
			cout<<"1000";
	}
	else
		cout<<"0000";
	return 0;
}
