#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	 int c1,c2;
	 string s1,s2;
	 cin>>c1>>s1>>c2>>s2;
	 if(c1!=c2)
	 {
	 	cout<<"0000";
	 	return 0;
	 } 
	 bool a,b,c,d;
	 a=b=c=d=0;
	 if(c1==c2)
	 {
	 	a=1;
	 	int x,y;
		x=0,y=0;
		x=(s1[0]-'0')*10+(s1[1]-'0');
		y=(s2[0]-'0')*10+(s2[1]-'0');
		if(x==y)
		{
			b=1;
			if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B')))
			{
				c=1;
				if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
				{
					d=1;
				}
				else
				if(s1[2]=='A'&&s2[2]=='B')
				{
					d=1;
				}
				else
				if(s1[2]=='B'&&s2[2]=='C')
				{
					d=1;
				}
				else
				if(s1[2]=='B'&&s2[2]=='A')
				{
					d=1;
				}
				else
				if(s1[2]=='C'&&s2[2]=='B')
				{
					d=1;
				}
			}
		} 
	 }
	 cout<<a<<b<<c<<d;
	return 0;
}
