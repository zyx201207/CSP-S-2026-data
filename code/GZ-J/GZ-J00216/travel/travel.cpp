//GZ-J00216 敖德钦 贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,c,p,x,x1;
string s,s1,s2,s3,s4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	x=int(s[0]-'0');
	x*=10;
	x+=int(s[1]-'0');
	x1=int(s2[0]-'0');
	x1*=10;
	x1+=int(s2[1]-'0');
	if(x1!=x)
	{
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else
	{
		s4[1]='1';
		if(s1[0]==s3[0]&&s1[1]==s3[1])
		{
			s4[2]='1';
			if(s1[2]>='A'&&s1[2]<='C'&&s3[2]>='A'&&s3[2]<='C')
			{
				if((s1[2]=='A'&&s3[2]=='C')||(s1[2]=='C'&&s3[2]=='A'))
				{
					cout<<"1110";
				}
				else
				{
					cout<<"1111";
				}
			}
			else
			{
				if(s1[2]>='D'&&s1[2]<='F'&&s3[2]>='D'&&s3[2]<='F')
			{
				
				
				
					cout<<"1111";
				
			}
			else
			{
				cout<<"1100";
			}
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	
	fclose(stdin);
		fclose(stdout);
		return 0;
}
