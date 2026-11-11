#include <bits/stdc++.h>
using namespace std;
string s,c;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,m,num=0,sum=0;
	char a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>a;
		num+=m;
		for(int j=1;j<=m;j++)
		{
			s+=a;
		}
	}
	for(int i=num-1;i>=0;i--)
	{
		c+=s[i];
	}
	for(int i=0;i<=num;i++)
	{
		if(c[i]!=s[i])
		{
			c[i]=s[i];
			s[num-i-1]=s[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
