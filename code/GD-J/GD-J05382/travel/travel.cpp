#include <bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(nullptr);
using ll=long long;
string c1,s1,c2,s2;
string ans;
char a,b;
void near()
{
	if(abs(a-b)==1&&(!(a=='C'&&b=='D')&&!(a=='D'&&b=='C')))
	{
		ans+="1";
	}
}
void solve()
{
	cin>>c1>>s1>>c2>>s2;
	a=s1[2];
	b=s2[2];
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		ans+="1";
		string tmp1="",tmp2="";
		tmp1+=s1[0];
		tmp1+=s1[1];
		tmp2+=s2[0];
		tmp2+=s2[1];
		if(tmp1[0]==tmp2[0]&&tmp1[1]==tmp2[1])
		{
			ans+="1";
			if((a=='F'&&b=='D')||(a=='D'&&b=='F'))
			{
				ans+="1";
			}
			else if(a=='A')
   			{
   				if(b=='B'||b=='C')
   				{
   					ans+="1";
   					near();
				}
				else
				{
					ans+="00";
				}
			}
			else if(a=='B')
   			{
   				if(b=='A'||b=='C')
   				{
   					ans+="1";
   					near();
				}
				else
				{
					ans+="00";
				}
			}
			else if(a=='C')
   			{
   				if(b=='B'||b=='A')
   				{
   					ans+="1";
   					near();
				}
				else
				{
					ans+="00";
				}
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
}
signed main()
{
	ios;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	solve();
	return 0;
}

