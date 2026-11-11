#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[10000]={0},ans=0,sum=0;
	char c[10000]={0},s[10000]={0},s1[10000]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s[j]=c[i];
			ans++;
		}
	}
	
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			s1[j]=c[i];
		}
	}
	for(int i=1;i<=ans;i++)
	{
		if(s[i]!=s1[i])
		{
			sum++;
		}
	}
	cout<<sum;
	//3 2 a 2 b 1 c
	//Trick||Treat!
	//2 2 a 3 a
	//6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b



	return 0;
}
