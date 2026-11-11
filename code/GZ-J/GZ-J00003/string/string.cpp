//GZ-J00003 ¶­ÜÇÐù 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long nl=0;
	string s;
	for(int i=1;i<=n;i++)
	{
		int k;
		char v;
		cin>>k>>v;
		for(int j=1;j<=k;j++)
		{
			s+=v;
		}
		nl+=k;
	}
	s=" "+s;
	if(nl%2==1)
	{
		long long ans=0;
		for(int i=1;i<(nl+1)/2;i++)
		{
			if(s[i]!=s[i+(nl+1)/2])
			{
				ans++;
			}	
		}
		cout<<ans;
	}
	else
	{
		long long ans=0;
		for(int i=1;i<nl/2;i++)
		{
			if(s[i]!=s[i+nl/2])
			{
				ans++;
			}	
		}
		cout<<ans;
	}
	return 0;
}
