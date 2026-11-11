#include<bits/stdc++.h>
using namespace std;
string sc,sr,xc,xr;
int main() {
	freopen("tmp.in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>sc>>sr>>xc>>xr;
	cout<<(sc==xc);
	int a,b;
	a= sr[2]-'A',b= xr[2]-'A';
	int x= (sr[0]-'0')*10+(sr[1]-'0');
	int y= (xr[0]-'0')*10+(xr[1]-'0');
	//-------------------------
	cout<<(x==y);
	bool f= (x==y) & (a<=2 && b<=2) || (a>=3 && b>=3);
	cout<<f;
	bool e;
	e= (x==y) & ((abs(b-a)==1 && a<=2 && b<=2) || (abs(b-a)==2 && a>=3 && b>=3));
	cout<<e;
	return 0;
}
