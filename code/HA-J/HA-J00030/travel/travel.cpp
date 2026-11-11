#include<bits/stdc++.h>
using namespace std;
string rc,rw,xc,xw;
bool c,p,g,l,ce; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>rc>>rw>>xc>>xw;
	c=(rc==xc);
	cout<<c;
	p=(rw[0]==xw[0])&&(rw[1]==xw[1])&&c;
	cout<<p;
	bool rl=(rw[2]=='A'||rw[2]=='B'||rw[2]=='C');
	bool wl=(xw[2]=='A'||xw[2]=='B'||xw[2]=='C');
	g=!(rl^wl)&&p;
	cout<<g;
	ce=(rw[2]=='B'||xw[2]=='B'||rw[2]=='D'||rw[2]=='D')&&g;
	cout<<ce;
	return 0;
}
