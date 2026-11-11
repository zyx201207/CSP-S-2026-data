#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,m;
	string c,d,s;
	cin>>a>>c>>b>>d;
	s="0000";
	if(a==b)
	{
		s[0]='1';
		if(c[0]==d[0]&&c[1]==d[1])
		{
			s[1]='1';
			if(c[2]-'A'<=2&&d[2]-'A'<=2)
			{
				s[2]='1';
				m=c[2]-d[2];
				if(m==1||m==-1)
				{
					s[3]='1';
				}
			}
			else if(c[2]-'A'<=5&&d[2]-'A'<=5)
			{
				s[2]='1';
				s[3]='1';
			}
		}
	}
	cout<<s;
	return 0;
}
