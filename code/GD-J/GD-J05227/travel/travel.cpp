#include<bits/stdc++.h>
using namespace std;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rs,xc,xs;
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc) a=1;
	if(a&&rs[0]==xs[0]&&rs[1]==xs[1]) b=1;
	if(b&&((rs[2]<'D'&&xs[2]<'D')||(rs[2]>'C'&&xs[2]>'C'))) c=1;
	if(c&&((char(rs[2]-1)==xs[2])||(char(xs[2]-1)==rs[2]))) d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
