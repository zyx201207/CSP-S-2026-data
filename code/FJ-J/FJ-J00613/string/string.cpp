#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s1="";
	for(int i=1;i<=n;i++)
	{
		long long k;
		char c;
		cin>>k>>c;
		for(int i=1;i<=k;i++)
		{
			s1+=c;
		}
	}
	string s=s1;
	reverse(s1.begin(),s1.end());
	if(s1==s) 
	{
		cout<<0;
		return 0;
	}
	else
	{
		long long len=s.size();
		long long xg=len/2;
		long long sum=0;
		if(len%2)
		{
			for(int i=xg+1;i<len;i++)
			{
				if(s[i]!=s[len-i-1]) sum++;
			}
		}
		else 
		{
			for(int i=xg;i<len;i++)
			{
				if(s[i]!=s[len-i-1]) sum++;
			}
		}
		cout<<sum;
	}
	return 0;
}
