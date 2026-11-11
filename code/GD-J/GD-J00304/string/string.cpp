#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		string y;
		cin>>x>>y;
		string v=y;
		for(int j=1;j<=x;j*=2)
		{
			if(v.size()*2>x)
			{
				for(int k=1;k<=x-v.size();k++)
				{
					v+=y;
				}
				continue;
			}
			v+=v;
		}
		s+=v;
	}
	if(s.size()%2==1)
	{
		for(long long i=0;i<(s.size()-1)/2;i++)
		{
			if(i==0 && s[i]!=s[s.size()-1]) 
			{
				ans++;
				continue;
			}
			if(s[i]!=s[i*2+1])
			{
				ans++;
			 } 
		}
	}
	else
	{
		for(long long i=0;i<s.size()/2;i++)
		{
			if(i==0 && s[i]!=s[s.size()-1]) 
			{
				ans++;
				continue;
			}
			if(s[i]!=s[i*2])
			{
				ans++;
			 } 
		}
	}
	cout<<ans;
	return 0;
 }
