#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[100005]; 
	cin>>n;
	int sum=0;
	int t=1;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		for(int j=1;j>=a;j++)
		{
			s[t]=b;
			t++;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(s[i]!=s[i-1])
		{
			sum++;
			s[i]=s[i-1];
		}
	}
	cout<<sum;
	return 0;
}
