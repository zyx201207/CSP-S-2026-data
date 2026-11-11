#include<bits/stdc++.h>
using namespace std;
int huiwen(string a)
{
	string b=a;
	reverse(a.begin(),a.end());
	if (a==b)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,a,sum=0;
	char c;
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		for (int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	if (huiwen(s))
	{
		cout<<0;
		return 0;
	}
	long long b=s.size();
	for (long long i=0;i<b/2;i++)
	{
		if (s[i]!=s[b-i-1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
