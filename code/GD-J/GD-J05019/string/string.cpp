#include <bits/stdc++.h>
using namespace std;
int n,a[200005],cnt=0,x;
char c[200005],s[10000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=a[i];j++)
		{
			cnt++;
			s[cnt]=c[i];
		}
	}
	int sum=0;
	for (int i=1;i<=cnt/2;i++)
	{
		if (s[i]!=s[cnt-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
