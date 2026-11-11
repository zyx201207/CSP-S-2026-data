#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;

	if(c1!=c2) {
		cout<<"0000"<<endl;
		return 0;
	} else { 
		if(s1[0]!=s2[0] || s1[1]!=s2[1]) {
			cout<<"1000"<<endl;
			return 0;
		} 
		else {
			if((s1[2]=='C'&&s2[2]!='D')||(s1[2]=='D'&&s2[2]!='F')||(s1[2]!='D'&&s2[2]!='F') || (s1[2]!='F'&&s2[2]!='D')|| (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) {
				if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) {
					cout<<"1111"<<endl;
					return 0;
				} else if(s1[2]+1==s2[2]) {
					cout<<"1111"<<endl;
					return 0;
				} else if(s1[2]-1==s2[2]) {
					cout<<"1111"<<endl;
					return 0;
				} else {
					cout<<"1110"<<endl;
					return 0;
				}
			} else {
				cout<<"1100"<<endl;
				return 0;
			}
		}
	}
	return 0;
}


