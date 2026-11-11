#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2))
		{
			cout<<1;
			char seat1=s1[2],seat2=s2[2];
//			cout<<seat1<<" "<<seat2;
			if(('A'<=seat1&&seat1<='C'&&'A'<=seat2&&seat2<='C')||('D'<=seat1&&seat1<='F'&&'D'<=seat2&&seat2<='F'))
			{
				cout<<1;
				if(seat1+1==seat2||seat2+1==seat1)cout<<1;
				else cout<<0;
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
