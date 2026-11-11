#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string z,x,c,v;
	bool a,s,d,d1,d2,f;
	cin>>z>>x>>c>>v;
	a=(z==c);
	s=((x[0]==v[0])&&(x[1]==v[1]));
	d1=((x[2]=='A'||x[2]=='B'||x[2]=='C')&&(v[2]=='A'||v[2]=='B'||v[2]=='C'));
	d2=((x[2]=='D'||x[2]=='F')&&(v[2]=='D'||v[2]=='F'));
	d=((d1||d2)&&s);
	f=(d2||((d1&&x[2]-1==v[2])||(d1&&x[2]+1==v[2])));
	cout<<a<<s<<d<<f;
	return 0;
}
