#include<bits/stdc++.h>
using namespace std;
int n;
string b,c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		string k;
		cin>>a>>k;
		for(int j=1;j<=a;j++)
		{
			b+=k;
		}
	}
	for(int i=n;i>=1;i--)
	{
		c[n-i+1]=b[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=c[i])
		{
			b[i]=c[i];
			sum++;
		}
	}
	cout<<sum;
}
