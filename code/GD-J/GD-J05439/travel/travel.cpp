#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b) cout<<"0000";
	else {
		string x,y;
		for(int i=0; i<2; i++) x+=s1[i],y+=s2[i];
		if(x!=y) cout<<"1000";
		else {
			cout<<"11";
			bool f=0;
			char ca=s1[2],cb=s2[2];
			if(ca=='A'||ca=='B'||ca=='C') {
				if(cb=='A'||cb=='B'||cb=='C') {
					cout<<"1";
					f=1;
				}
			} else if(ca=='D'||ca=='E') {
				if(cb=='D'||cb=='E') {
					cout<<"1";
					f=1;
				}
			}
			if(!f) cout<<"00";
			else {
				if(ca==char(cb+1)||ca==char(cb-1)) {
					cout<<"1";
				} else cout<<"0";
			}
		}
	}
	return 0;
}
