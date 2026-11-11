#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,p1,p2,nnnnnnnn;
bool f1,f2,f3,f4;
int x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	p1=b[0]+b[1];
	p2=d[0]+d[1];
	x=b[2]-'A';
	y=d[2]-'A';
	if(a==c)
		f1=1;
	if(p1==p2 and f1)
		f2=1;
	if(f2 and ((d[2]>='D' and b[2]>='D') or (d[2]<='C' and b[2]<='C')))
		f3=1;
	if(f3 and abs(x-y)==1)
		f4=1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
