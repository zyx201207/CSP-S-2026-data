#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;c1[i];i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(s1[2]<='C' && s2[2]<='C')
	{
		if(s1[2]=='B' || s2[2]=='B')
		{
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
