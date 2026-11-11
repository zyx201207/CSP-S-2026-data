#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a;
	char k;
	string s = "";
	for(long long i = 1;i <= n;i++)
	{
		cin>>a>>k;
		for(long long j = 1;j <= a;j++)
		{
			s+=k;
		}
	}
	long long ans = 0;
	long long t = s.length();
	for(long long i = 0;i < t/2;i++)
	{
		if(s[i]!=s[t-i-1])
		{
			ans++;
		}
	} 
	cout<<ans;
}
