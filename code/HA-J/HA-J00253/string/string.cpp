#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000001];
string s,z,x;
bool f[100000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	int tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>x[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=x[i];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=a[i];j>=1;j--)
		{
			z+=x[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]==z[i])
		{
			f[i]=1;
		}
		else
		{
			f[i]=0;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
