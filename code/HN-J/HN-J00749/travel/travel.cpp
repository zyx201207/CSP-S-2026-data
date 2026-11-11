#include <bits/stdc++.h>
using namespace std;
struct Trc
{
	int cx;
	int cn;
	char cl;
} r,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cz;
	cin>>r.cx;
	cin>>cz;
	r.cl=cz[2];
	if(cz[0]=='0')
		r.cn=cz[1]-'0';
	else
		r.cn=10+cz[1]-'0';
	cin>>x.cx;
	cin>>cz;
	x.cl=cz[2];
	if(cz[0]=='0')
		x.cn=cz[1]-'0';
	else
		x.cn=10+cz[1]-'0';
	if(x.cl=='D') x.cl='E';
	if(r.cl=='D') r.cl='E';
	string ans="";
	if(r.cx==x.cx) ans+='1';
	else ans+='0';
	if(r.cx==x.cx && r.cn==x.cn) ans+='1';
	else ans+='0';
	if(r.cx==x.cx && r.cn==x.cn &&
	  (r.cl<'D' && x.cl<'D' || r.cl>'D' && x.cl>'D')) ans+='1';
	else ans+='0';
	if(r.cx==x.cx && r.cn==x.cn && abs(r.cl-x.cl)==1) ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
