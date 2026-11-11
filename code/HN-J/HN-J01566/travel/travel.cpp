#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,c1,c2;
char x,y;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>c1>>c2;
	if(s1!=c1)
	{
		cout<<"0000";
		return 0;
	}
	int a=0,b=0;
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')
		{
			a=a*10+s2[i]-'0';
		}
		if(s2[i]>='A'&&s2[i]<='Z')
		{
			x=s2[i];
		}
	}
	for(int i=0;i<c2.size();i++)
	{
		if(c2[i]>='0'&&c2[i]<='9')
		{
			b=b*10+c2[i]-'0';
		}
		if(c2[i]>='A'&&c2[i]<='Z')
		{
			y=c2[i];
		}
	}
	if(a==b)
	{
		if(x<='C'&&y<='C')
		{
			if(x-y==1||y-x==1) cout<<"1111";
			else cout<<"1110";
		}
		else if(x>='D'&&y>='D')
		{
			cout<<"1111";
		}
		else
		{
			cout<<"1100";
		}
	}
	else cout<<"1000";
	return 0;
}
