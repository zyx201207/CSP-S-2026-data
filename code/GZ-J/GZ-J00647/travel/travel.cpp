//GZ-J00647 盘州市第二中学 王玺童 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rs,cx,sx,s;
	cin>>rc>>rs>>cx>>sx;
	if(rc==cx) s+='1';
	else s+='0';
	string r=" ";
	string x=" ";
	for(int i=0;i<2;i++)
	r+=rs[i];
	for(int i=0;i<2;i++)
	x+=sx[i];
	if(r==x) s+='1';
	else s+='0';
	if(rs[2]<='C'&&sx[2]<='C') s+='1';
	else
	if(rs[2]>'C'&&rs[2]<='F'&&sx[2]>'C'&&sx[2]<='F') s+='0';
	else s+='0';
	char q=rs[2],e=sx[2];
	bool o=1;
	if(e=='D')
	{
		if(q+1=='D')
		{
			s+='0';
			o=0;
		 } 
	}
	if(q=='D')
	if(e+1==q)
	{
		s+='0';
		o=0;
	 } 
	if(o>0) if(abs(q-e)==1) s+='1';
	else
	if((q=='E'&&e=='F')||(q=='F'&&e=='E')) s+='1';
	else s+='0';
	cout<<s;
	return 0;
}
