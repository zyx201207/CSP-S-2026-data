#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,x1,x2;
	char a,b,c,d,e,f;
	cin>>c1>>c2>>x1>>x2;
	if(c1!=x1) 
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	a=c2[0];
	b=c2[1];
	e=c2[2];
	c=x2[0];
	d=x2[1];
	f=x2[2];
	if(a!=c||b!=d)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(('A'<=e&&e<='C'&&'A'<=f&&f<='C')||('D'<=e&&e<='F'&&'D'<=f&&f<='F'))
	{
		cout<<"1";
		if(e-f==1||f-e==1)
		{
			if((e!='C'&&f!='D')||(e!='D'&&f!='C'))
			{
				cout<<"1";
				return 0;
			}
		}
		cout<<"0";
	}
	else cout<<"00";
	return 0;
}
