#include <bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)cout<<1;
	else cout<<0;
	if(cr==cx&&sr[0]==sx[0]&&sr[1]==sx[1])cout<<1;
	else cout<<0;
	if(cr==cx&&sr[0]==sx[0]&&sr[1]==sx[1]&&((sr[2]<='C'&&sx[2]<='C')||(sr[2]>'C'&&sx[2]>'C')))cout<<1;
	else cout<<0;
	if(cr==cx&&sr[0]==sx[0]&&sr[1]==sx[1]&&((sr[2]<='C'&&sx[2]<='C')||(sr[2]>'C'&&sx[2]>'C'))&&(abs(sr[2]-'A'-(sx[2]-'A'))==1||(sr[2]=='F'&&sx[2]=='D')||(sx[2]=='F'&&sr[2]=='D')))cout<<1;
	else cout<<0;
	return 0;
}
