#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb)
	{
		ans+='1';
		string t=sa.substr(0,2),d=sb.substr(0,2);
		if(t==d)
		{
			ans+='1';
			char a=sa[2],b=sb[2];
			if((a=='A' or a=='B' or a=='C')and(b=='A' or b=='B' or b=='C'))
			{
				ans+='1';
				if(a=='A' and b=='B' or a=='B' and b=='A' or a=='B' and b=='C' or b=='B' and a=='C')
				{
					ans+='1';
				}
				else
				{
					ans+='0';
				}
			}
			else if((a=='D' or a=='E')and(b=='E' or b=='D'))
			{
				ans="1111";
			}
			else
			{
				ans="1100";
			}
		}
		else
		{
			ans="1000";
		}
	}
	else
	{
		ans="0000";
	}
	cout<<ans;
	return 0;
}
