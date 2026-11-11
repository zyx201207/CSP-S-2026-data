#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	int rcx,xcx,rpp,xpp;
	rcx=(c[0]-'0')*10+c[1]-'0';
	xcx=(cc[0]-'0')*10+cc[1]-'0';
	if(rcx!=xcx) {
		cout<<"0000";
	} else {
		cout<<"1";
		rpp=(s[0]-'0')*10+s[1]-'0';
		xpp=(ss[0]-'0')*10+ss[1]-'0';
		if (rpp!=xpp) {
			cout<<"000";
		} else {
			cout<<"1";
			if((s[2]<='C' && ss[2]<='C')|| (s[2]>'C' && ss[2]>'C')) {
				cout<<"1";
				if ((abs(s[2]-ss[2])==1 &&s[2]<='C' && ss[2]<='C') || (s[2]=='D' && ss[2]=='F') || (s[2]=='F' && ss[2]=='D')){
					cout<<"1";
				} 
				else {
					cout<<"0";
				}
			} 
			else {
				cout<<"00";
			}
		}
	}
	return 0;
}
