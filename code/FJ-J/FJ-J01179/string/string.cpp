#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	vector <char> s;
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		long long a;
		char b;
		cin>>a>>b;
		for (long long i=1;i<=a;i++)
		{
			s.push_back(b);
		}
	}
	long long d=-1;
	for (long long i=n-1;i>=0;i--)
	{
		d++;
		if (s[i]!=s[d]) ans++;
	}
	cout<<ans;
}
