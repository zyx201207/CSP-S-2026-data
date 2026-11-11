#include<bits/stdc++.h>
using namespace std;
int a[2][200005];
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,e,b,c,d,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[1][i]>>a[2][i];
	}
	e=1;
	b=n;
	c=a[1][1];
	d=a[1][n];
	while(e!=b&&c!=d)
	{
		if(a[2][e]!=a[2][b])
		{
			sum++;
		}
		c--;
		d--;
		if(c==0)
		{
			e++;
			c=a[1][e];
		}
		if(d==0)
		{
			b--;
			c=a[1][b];
		}
	}
	cout<<sum;
	return 0;
}
