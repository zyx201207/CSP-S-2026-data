#include <bits/stdc++.h>
using namespace std;
char c[200005];
int a[200005],s[10000008],n,sum,m=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s[m]=c[i]-'a';
			m++;
		}
	}
	for(int i=1;i<=m/2;i++)
	{
		if(s[i]!=s[m-i])
		    sum++;
	}
	cout<<sum;
	return 0; 
}
