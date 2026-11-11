#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int main()
{
	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		ans+="1";
		bool p=1;
		for(int i=0;i<=1;i++)
		{
			if(b[i]!=d[i]) 
			{
				p=0;
				break;
			}
		}
		if(p)
		{
			ans+="1";
			if((b[2]-'A'<=2&&d[2]-'A'<=2)||(b[2]-'A'>=3&&d[2]-'A'>=3))
			{
				ans+="1";
				bool m=0;
				if(b[2]-'A'>=3&&d[2]-'A'>=3)
				{
					m=1;
					ans+="1";
				}
				else
				{
					if(b[2]-'A'>d[2]-'A')
					{
						if(b[2]=='B')
						{
							m=1;
							ans+="1";
						}
						else if(b[2]=='C'&&d[2]=='B')
						{
							m=1;
							ans+="1";
						}
					}
					else
					{
						if(d[2]=='B')
						{
							m=1;
							ans+="1";
						}
						else if(d[2]=='C'&&b[2]=='B')
						{
							m=1;
							ans+="1";
						} 
					}
				}
				if(!m)
				{
					ans+="0";
				}
			}
			else
			{
				ans+="00";
			}
		}
		else
		{
			ans+="000";
		}
	}
	else
	{
		ans+="0000";
	}
	cout<<ans;
	return 0;
} 
