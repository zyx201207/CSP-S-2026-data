#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string w,ww,s,ss;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>w>>ww>>s>>ss;
	if(w==s) {
		a=1;
		if(ww[0]==ss[0]&&ww[1]==ss[1]) {
			b=1;
			if(((ww[2]=='A'||ww[2]=='B'||ww[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'))||((ww[2]=='D'||ww[2]=='F')&&(ss[2]=='D'||ss[2]=='F'))) {
				c=1;
				if((ww[2]=='A'&&ss[2]=='B')||(ww[2]=='B'&&ss[2]=='A')||(ww[2]=='B'&&ss[2]=='C')||(ww[2]=='C'&&ss[2]=='B')||(ww[2]=='D'&&ss[2]=='F')||(ww[2]=='F'&&ss[2]=='D'))d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
