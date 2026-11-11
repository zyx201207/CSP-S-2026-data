#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	char v;
	cin>>n;
	long long x,tot=1;
	char s[2000005];
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cin>>v;
		for(int j=1;j<=x;j++)
		{
			s[tot]=v;
			tot++;
		}
	}

	int sum=0;
	for(int i=1;i<=(tot-1)/2;i++)
	{
		if(s[i]!=s[tot-i])
		{
			sum++;
		}
		else
		{
			continue;
		}
	}
	cout<<sum;
}
