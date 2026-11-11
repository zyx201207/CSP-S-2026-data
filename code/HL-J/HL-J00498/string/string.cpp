#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long t;
		char c;
		cin>>t>>c;
		for(long long j=1;j<=t;j++)
		{
			s+=c;
		}
	}
	string ss=s;
	long long l=s.size();
	long long mid=l/2+l%2;
	for(long long i=mid-1;i<l;i++)
	{
		s[i]=s[l-1-i];
	}
	for(long long i=0;i<l;i++)
	{
		if(ss[i]!=s[i]) ans++;
	}
	cout<<ans;
	return 0;
}
