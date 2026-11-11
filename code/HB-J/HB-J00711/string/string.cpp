#include <bits/stdc++.h>
using namespace std;
bool p(string s)
{
	int x=s.size();
	for(int i=0;i<x;i++)
	{
		if(s[i]==s[x-i+1])
		{
			return false;
		}
	}
	return true;
}
int q(string s)
{
	int x=s.size();
	int cnt=0;
	for(int i=0;i<x;i++)
	{
		if(s[i]==s[x-i+1])
		{
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,y;
	cin>>n;
	string s;
	char x1,y1;
	for(int i=1;i<=n;i++)
	{
		int a;
		char b;
		int c=s.size();
		cin>>a>>b;
		for(int j=c;j<c+a;j++)
		{
			s[j]=b;
		}
		if(i==1)
		{
			x=a;
			x1=b;
		}
		if(i==2)
		{
			y=a;
			y1=b;
		}
	}
	if(n<=1)
	{
		cout<<0;
	}
	else if(n==2&&x1!=y1)
	{
		if(x<y)
		{
			cout<<x;
		}
		else if(x==y)
		{
			cout<<x;
		}
	}
	else if(p(s))
	{
		cout<<0;
	}
	else
	{
		cout<<q(s);
	}
	return 0;
}

