#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	long long d=0;
	string s="";
	char b[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	int c=s.length();
	for(int i=0;i<c/2;i++)
	{
		if(s[i]!=s[c-i-1])
		{
			d++;
		}
	}
	cout<<d;
}
