//GZ-J00441   遵义市第十二中学   杜奕辰
#include <bits/stdc++.h>
using namespace std;
int a,b;
int main() {
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c3,s2;
	cin>>a>>s1>>b>>s2;
	if(a!=b) {
		cout<<"0000";
		return 0;
	} else {
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			cout<<"1";
			if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') {
				cout<<"1";
				if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		} else {
			cout<<"000";
			return 0;
		}
	}
	return 0;
}

