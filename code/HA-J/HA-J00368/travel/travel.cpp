#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int e=0,f=0,g=0;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1])
	{
		e=1;
		cout<<"1";
	}
	else
		cout<<"0";
	if(b[0]==d[0]&&b[1]==d[1]&&e==1)
	{
		g=1;
		cout<<"1";
	}
	else
		cout<<"0";
	if(e==1&&g==1&&(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'))
	{
		cout<<"1";
		f=1;
	}
	else
		cout<<"0";
	if(f==1&&(b[2]-d[2]==1||d[2]-b[2]==1))
		cout<<"1";
	else
		cout<<"0";
	return 0;
	
}