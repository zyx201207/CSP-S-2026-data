#include<bits/stdc++.h>
using namespace std;
long long n,a,m,x;
char c,s[1000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s[m+1]=c;
			m++;
		}
	}
	for(int i=1;i<=m/2;i++)
	{
		if(s[i]!=s[m-i])
		{
			x++;
		}
	}
	cout<<x;
	return 0;
}
