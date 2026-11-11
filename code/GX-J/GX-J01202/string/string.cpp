#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n;
string s;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++)
			s+=c;
	}
	cout<<s;
	long long len=s.size();
	for(int i=0;i<=(len-1)/2;i++)
	{
		if(s[i]!=s[len-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
