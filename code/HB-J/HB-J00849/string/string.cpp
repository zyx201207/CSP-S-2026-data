#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		long long t;
		char c;
		cin>>t>>c;
		while(t--)
		{
			s+=c;
		}
	}
	//cout<<s;
	long long mid=(s.size()+1)/2-1;
	if(s.size()%2==1)
	{
		//left of mid==right of mid
		long long ans=0;
		for(long long i=0;i<mid;i++)
		{
			long long c1=s[i],c2=s[s.size()-i-1];
			if(c1!=c2) ans++;
		}
		cout<<ans;
	}
	else if(s.size()%2==0)
	{
		//left of mid and mid==right of mid
		long long ans1=0;
		for(long long i=0;i<=mid;i++)
		{
			long long c1=s[i],c2=s[s.size()-i];
			if(c1!=c2) ans1++;
		}
		cout<<ans1;
	}
	return 0;
}
