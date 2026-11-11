#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,p1,p2,z1,z2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	p1=(s1[0]-'0')*10+s1[1]-'0';
	p2=(s2[0]-'0')*10+s2[1]-'0';
	switch(s1[2])
	{
		case 'A': z1=1; break;
		case 'B': z1=2; break;
		case 'C': z1=3; break;
		case 'D': z1=4; break;
		case 'F': z1=5; break;
	}
	switch(s2[2])
	{
		case 'A': z2=1; break;
		case 'B': z2=2; break;
		case 'C': z2=3; break;
		case 'D': z2=4; break;
		case 'F': z2=5; break;
	}
	if(c1==c2)
	{
		cout<<1;
		if(p1==p2)
		{
			cout<<1;
			if((z1<=3&&z2<=3)||(z1>=4&&z2>=4))
			{
				cout<<1;
				if((z1-z2)*(z1-z2)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
