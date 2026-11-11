#include<bits/stdc++.h>
using namespace std;
long long n,m,a[210000],b[210000],c,ans=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m)
	{
		cin>>a[1]>>a[2];
		c=a[1]&a[2];
		for(int i=3;i<=n;i++)
		{
			cin>>a[i];
			c=c&a[i];
		}
		cout<<c<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=m;i>=1;i--)
	{
		b[i]=m-i+1;
	}
	while(1)
	{
		for(int i=1;i<=n;i++)
		{
			if(b[i]==n-i+2)
			{
				b[i]=b[i+1]+2;
				b[i+1]+=1;
			}
		}
		if(b[1]>n)
		{
			break;
		}
		c=a[b[1]]&a[b[2]];
		for(int i=3;i<=m;i++)
		{
			c=c&a[b[i]];
		}
		ans=max(ans,c);
		c=0;
		b[1]++;
	}
	cout<<ans<<endl;
	return 0;
}
