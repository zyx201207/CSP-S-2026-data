#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	bool a1=false,b1=false,c1=false,d1=false;
	string a2,b2,c2,d2;
	cin>>a2>>b2>>c2>>d2;
	if(a2==c2)a1=true;
	if(a1)
	{
		if(b2[0]==d2[0]||b2[1]==d2[1])b1=true;
		if(b1)
		{
			if(((b2[2]=='A'||b2[2]=='B'||b2[2]=='C')&&(d2[2]=='A'||d2[2]=='B'||d2[2]=='C'))||((b2[2]=='D'||b2[2]=='F')&&(d2[2]=='D'||d2[2]=='F')))c1=true;
			if(c1)
			{
				if(abs(b2[2]-d2[2])==1)d1==true;
			 } 
		}
	}
	cout<<a1<<b1<<c1<<d1;
	return 0;
}
