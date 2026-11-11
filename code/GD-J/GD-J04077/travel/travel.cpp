#include <bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		if(s[0]==ss[0]&&s[1]==ss[1])
		{
			if((s[2]>='D'&&s[2]<='F'&&ss[2]>='D'&&ss[2]<='F')||(s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C'))
			{
				if(abs(s[2]-ss[2])==1||(s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D'))
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	
	return 0;
}
