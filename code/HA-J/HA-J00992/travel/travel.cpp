#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1.compare(c2)==0) {
		cout<<"1";
		string h1=s1.substr(0,2);
		string h2=s2.substr(0,2);
		if(h1.compare(h2)==0) {
			cout<<"1";
			int a=s1[2]-'A';
			int b=s2[2]-'A';
			if((a<=2&&b<=2)||(b>=3&&a>=3)) {
				cout<<"1";
				if(abs(a-b)==1) {
					cout<<"1";
					return 0;
				} else {
					cout<<"0";
					return 0;
				}
			} else {
				cout<<"00";
				return 0;
			}
		} else {
			cout<<"000";
			return 0;
		}
	}
	else cout<<"0000";
	return 0;
}

