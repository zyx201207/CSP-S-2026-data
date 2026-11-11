#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=true;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	string x="";
	for(int i=0;s1[i];i++)
	{
		if(s1[i]>='0' && s1[i]<='9')
		{
			x+=s1[i];
		}
	}
	string y="";
	for(int i=0;s2[i];i++)
	{
		if(s2[i]>='0' && s2[i]<='9')
		{
			y+=s2[i];
		}
	}
	if(x==y)
	{
		cout<<"1";
	}
	else
	{
		cout<<0;
		a=false;
	}
	
	x="";
	y="";
	for(int i=0;s1[i];i++)
	{
		if(s1[i]>='A' && s1[i]<='Z')
		{
			x+=s1[i];
		}
	}
	for(int i=0;s2[i];i++)
	{
		if(s2[i]>='A' && s2[i]<='Z')
		{
			y+=s2[i];
		}
	}
	if(a==false)
	{
		cout<<0;
	}
	else if((x=="A" && y=="B") || (x=="A" && y=="C") || (x=="B" && y=="C") || (x=="D" && y=="F") || (y=="A" && x=="B") || (y=="A" && x=="C") || (y=="B" && x=="C") || (y=="D" && x=="F"))
	{
		cout<<"1";
	}
	else
	{
		cout<<0;
		a=false;
	}
	if(a==false)
	{
		cout<<0;
	}
	else if((x=="A" && y=="B")  || (x=="B" && y=="C") || (x=="D" && y=="F") || (y=="A" && x=="B")  || (y=="B" && x=="C") || (y=="D" && x=="F"))
	{
		cout<<"1";
		return 0;
	}
	else
	{
		cout<<0;
		return 0;
	}
} 
