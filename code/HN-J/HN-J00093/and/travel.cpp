#include<bits/stdc++.h>
using namespace std;

bool check1(string s,string t)
{
	return (s[2]>68)^(t[2]>68);
}

int main()
{
//	freopen("C:/Users/Administrator/Desktop/travel/travel5.in","r",stdin);
//	freopen("C:/Users/Administrator/Desktop/travel.txt","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string s,t;
	cin>>n>>s>>m>>t;
	if(s[2]=='D')
	{
		s[2]='E';
	}
	if(t[2]=='D')
	{
		t[2]='E';
	}
	if(n==m)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s.substr(0,2)==t.substr(0,2))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s.substr(0,2)==t.substr(0,2)&&!check1(s,t))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(s.substr(0,2)==t.substr(0,2)&&abs(s[2]-t[2])==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

