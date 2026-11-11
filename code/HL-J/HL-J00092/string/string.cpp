#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	while (n--)
	{
		long long a;
		char c;
		cin>>a>>c;
		for (long long i=1;i<=a;i++)
		{
			s+=c;
		}
	} 
	string t=s;
	reverse(t.begin(),t.end());
	if (t==s)
	{
		cout<<0;
		return 0;
	}
	long long ans=0;
	if (s.size()%2==1)
	{
		unsigned long long ss=(s.size()+1)/2;
		for (long long i=0;i<ss;i++)
		{
			if (t[i]!=s[i])
			{
				ans++;
			} 
		} 
	} 
	else
	{
		unsigned long long ss=(s.size())/2;
		for (long long i=0;i<ss;i++)
		{
			if (t[i]!=s[i])
			{
				ans++;
			} 
		} 
	}
	cout<<ans;
	return 0;
}
