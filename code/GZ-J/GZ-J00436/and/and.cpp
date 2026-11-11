//GZ-J00436 贵阳市花溪区实验中学 于靖恩
#include<bits/stdc++.h>
using namespace std;
long long ze(long long a)
{
	long long n=0;
	while(a>0)
	{
		n=n+a%2*10;
		a/=2;
	}
	return n;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[10010],x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(x<a[i])
		{
			x=a[i];
		}
		a[i]=ze(a[i]);
	}
	if(m!=1)
	{
		x=0;
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				
			}
		}
	}
	cout<<x;
	return 0;
}
