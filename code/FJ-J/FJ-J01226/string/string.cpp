#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	for(long long i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long sum=0;
	if(s.size()%2==0)
	{
		for(long long i=s.size()/2;i<s.size();i++)
		{
			if(s[i]!=s[s.size()-i-1])
			{
				sum++;
			}
		}
	}
	else
	{
		for(long long i=s.size()/2+1;i<s.size();i++)
		{
			if(s[i]!=s[s.size()-i-1])
			{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
