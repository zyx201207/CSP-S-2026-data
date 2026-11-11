#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool solve(char c,char c2)//同一侧 
{
	if(c>c2)
	{
		swap(c,c2);
	}
	if((c=='A'&&(c2=='B'||c2=='C'))||(c=='B'&&(c2=='A'||c2=='C'))||(c=='C'&&(c2=='A'||c2=='B'))||(c=='D'&&c2=='F')||(c=='F'&&c2=='D'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool solve2(char c,char c2)//相邻 
{
	if(c>c2)
	{
		swap(c,c2);
	}
	if((c=='A'&&c2=='B')||(c=='B'&&c2=='C')||(c=='D'&&c2=='F'))
	{
		return true;
	}
	return false;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c,s,c2,s2;
	cin >> c>> s >> c2>> s2;
	string ans="";
	if(c==c2)
	{
		ans+='1';
		if(s[0]==s2[0]&&s[1]==s2[1])
		{
			ans+='1';
			if(solve(s[2],s2[2]))//同一侧？ 
			{
				ans+='1';
				if(solve2(s[2],s2[2]))//相邻？ 
				{
					ans+='1';
				}
				else
				{
					ans+='0';
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
		ans="0000";
	}
	cout<< ans;
	return 0;
}

