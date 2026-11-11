#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],idx1=1;
int b[500005],idx;
int findx(int k)
{
	for(int i=1;i<=idx;i++)
	{
		if(b[i]==k)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		idx=1;
		for(int j=i;j<=n;j++)
		{
			if(findx(a[j])==-1)
			{
				b[++idx]=a[j];
			}
			else
			{
				idx-=(idx-findx(a[j]));
			}
		}
		for(int i=1;i<=idx;i++)
		{
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
