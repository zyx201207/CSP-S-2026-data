#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long s[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1])
	{
		s[1]=1;
		if(b[0]-'0'==d[0]-'0'&&b[1]-'0'==d[1]-'0')
		{
			s[2]=1;
			if(b[2]-'A'<3&&d[2]-'A'<3)
			{
				s[3]=1;
				if(!s[4])
				{
					if(abs(b[2]-'A'-d[2]+'A')==1)s[4]=1;
					else s[4]=0;
				}
			}
			else s[3]=0;
		}
		else if(b[0]==d[0]&&abs(b[1]-d[1])==1&&b[2]==d[2])s[4]=1;
		else s[2]=0;
	}
	else s[1]=s[2]=s[3]=s[4]=0;
	cout<<s[1]<<s[2]<<s[3]<<s[4];
	return 0;
} 
