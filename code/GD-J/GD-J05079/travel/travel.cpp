#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
string c1,s1,c2,s2,ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	//判断是否在同一节车厢，即车厢号相同
	if(c1==c2)
	{
		ans+='1';
	}
	else
	{
		ans+='0';
	}
	//判断是否在同一排，即座位号前两位数字相同
	if(ans[0]=='0')//不在同一节车厢，直接输出0 
	{
		ans+='0';
	}
	else
	{
		if(s1[0]+s1[1]==s2[0]+s2[1])
		{
			ans+='1';
		}
		else
		{
			ans+='0';
		}
	}
		
	//判断是否在同一排，且是否在同一侧 
	if(ans[1]=='0')//不在同一排，直接输出0 
	{
		ans+='0';
	}
	else if(ans[1]=='1')//在同一排，分类判断是否在同一侧 
	{
		if( (s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A'))
		{
			ans+='1';
		}
		else if( (s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A') )
		{
			ans+='1';
		}
		else if( (s1[2]=='B' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='B') )
		{
			ans+='1';
		}
		else if( (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D') )
		{
			ans+='1';
		}
		else
		{
			ans+='0';
		}
	}
	//判断是否相邻
	if(ans[2]=='0')//不在同一侧，直接输出0 
	{
		ans+='0';
	}
	else//在同一侧，分类判断 
	{
		if( (s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A'))
		{
			ans+='1';
		}
		else if( (s1[2]=='B' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='B') )
		{
			ans+='1';
		}
		else if( (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D') )
		{
			ans+='1';
		}
		else
		{
			ans+='0';
		}
	}
	cout << ans << endl;
	return 0;
}
