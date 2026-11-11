#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int j,p,c,x;
int main()
{
	cin.tie(0);cout.tie(0);
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		j=1;
		if(b2[0]==a2[0]&&b2[1]==a2[1])
		{
			p=1;
			if((b2[2]<='F'&&a2[2]<='F'&&b2[2]>='D'&&a2[2]>='D')
			||(b2[2]<='C'&&a2[2]<='C'&&b2[2]>='A'&&a2[2]>='A'))
			{
				c=1;
				if(abs(a2[2]-b2[2])==1||a2[2]+b2[2]=='D'+'F')
				{
					x=1;
				}
			}
		}
	}
	
	
	cout<<j<<p<<c<<x;
	return 0;
}

