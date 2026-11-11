#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ok,ok1,ok2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ok=1,cout<<"1";
	else cout<<"0"<<"0"<<"0"<<"0";
	if(ok==1) {
		if(s1.substr(0,2)==s2.substr(0,2)) ok1=1,cout<<"1";
		else cout<<"0"<<"0"<<"0";
	}
	for(int i=1; i<=3; i++) {
		if(ok1==1) {
			if('A'<=s1[i]&&s1[i]<='F'&&'A'<=s2[i]&&s2[i]<='F') {
				if('A'<=s1[i]&&s1[i]<='C'&&'A'<=s2[i]&&s2[i]<='C') {
					cout<<"1";
					ok2=1;
				} else if(s1[i]=='D'&&s2[i]=='F'||s2[i]=='D'&&s1[i]=='F') {
					cout<<"1"<<"1";
				} else cout<<"0"<<"0";
				if(ok2==1) {
					if(s1[i]=='A'&&s2[i]=='B'||s1[i]=='B'&&s2[i]=='A'||s1[i]=='B'&&s2[i]=='C'||s1[i]=='C'&&s2[i]=='B') {
						cout<<"1";
					} else cout<<"0";
				}
			}
		}

	}
	return 0;
}
