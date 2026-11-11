#include <bits/stdc++.h>
using namespace std;
long long a[27];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	string s="";
	for(int i=0;i<n;i++)
	{
		long long x;
		char c;
		cin>>x>>c;
		for(long long j=0;j<x;j++)
		{
			s+=c;
		}
		
	}
	for(int i=0;i<=sqrt(s.size());i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			s[s.size()-1-i]=s[i];
			ans++;	
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
