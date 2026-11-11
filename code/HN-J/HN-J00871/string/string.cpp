#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","f",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	string s,t;
	for(int i=1;i<=a;i++)
	{
		int x;
		char n;
		cin>>x;
		cin>>n;
		for(int i=1;i<=x;i++)
		{
			s+=n;	
		}			
	}
	for(int i=s.length();i>=0;i--)
	{
		t+=s[i];	
	}
	bool flage = 1;
	for(int i=1;i<=s.length();i++)
	{
		if(s[i]!=t[i])
		{
			flage=0;
			break;
		}
	}
	if(flage==1)
	{
		cout<<0;
		return 0;
	}
	int f;
	if(s.length()%2==1)
	{
		for(int i=1;i<=s.length()/2;i++)
		{
			if(s[i]!=s[s.length()-i])
			{
				s[s.length()-i]=s[i];
				f++;
			}
		}	
	}
	else
	{
		for(int i=1;i<=s.length()/2-1;i++)
		{
			if(s[i]!=s[s.length()-i])
			{
				s[s.length()-i]=s[i];	
				f++;
			}
			if(s[s.length()/2]!=s[s.length()/2+1])
			{
				s[s.length()/2+1]=s[s.length()/2];	
				f++;
			}	
		}
	}
	cout<<f;
	return 0;
}

