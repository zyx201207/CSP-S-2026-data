#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool f0=0,f1=0,f2=0,f3=0;
	int x,y;
	cin>>a>>b>>c>>d;
	x=(b[0]-'0')*10+(b[1]-'0');
	y=(d[0]-'0')*10+(d[1]-'0');
	f0=(a==c);
	f1=((x==y)&&f0);
	if(f1)
	{
		if((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C'))
    	f2=1;
    	else if((b[2]<='F'&&b[2]>='D')&&(d[2]<='F'&&d[2]>='D'))
    	f2=1;
    	else
    	f2=0;
	}
	else
	f2=0;
	if(((b[2]==(d[2]+1))||(d[2]==(b[2]+1)))&&f2)
	f3=1;
	else if(((x==y+1)||(y=x+1))&&f0&&(b[2]==d[2]))
	f3=1;
	else f3=0;
	cout<<f0<<f1<<f2<<f3<<endl;
 } 
