#include<bits/stdc++.h>
using namespace std;
string c,s;
int x,y;
char a,b;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>x>>a>>s>>y>>b;
	if(c==s) {
		cout<<1;
		bool f=0;
		if(x==y) {
			cout<<1;
			f=1;
		} else cout<<0;
		if(f==1) {
			if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='E'&&b>='D '&&b<='E'))cout<<1;
			else cout<<0;
		} else cout<<0;
		if(f==1) {
			if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='E')||(a=='E'&&b=='D'))cout<<1;
			else cout<<0;
		} else cout<<0;
	} else cout<<"0000";

	return 0;
}
