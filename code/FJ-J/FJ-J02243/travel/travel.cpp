#include<bits/stdc++.h> 
using namespace std;
string s,s1,s2,s3;
int a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3; 
	if(s==s2)
	{
		a=1;
		if(s1[1]==s3[1]&&s1[0]==s3[0])
		{
			b=1;
			if(s1[2]>='D'&&s3[2]>='D')
			{
				c=1;
				int p=abs(s1[2]-s3[2]);
				if(p==1)
				d=1;
			}
			if(s1[2]<='C'&&s3[2]<='C')
			{
				c=1;
				int p=abs(s1[2]-s3[2]);
				if(p==1)
				d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
 } 
