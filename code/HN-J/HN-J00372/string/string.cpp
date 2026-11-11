#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string a="";
	for(int i=0;i<n;i++)
	{
		long long x;
		cin>>x;
		string s;
		cin>>s;
		for(long long i=0;i<x;i++)
		{
			a+=s;
		}
	}
	long long ans=0,b=a.size();
	for(long long i=0;i<b/2;i++)
	{
		if(a[i]!=a[b-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
