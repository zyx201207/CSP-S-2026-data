#include<bits/stdc++.h>
using namespace std;
int main()
{
		freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ccc=0;
	int a[100005],b[100005],c[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int aaa=1+ccc;aaa<=n;aaa++)
	{
		for(int i=1+ccc;i<=n;i++)
		{
			c[i]=a[i];
		}
		for(int i=1;i<=n;i++)
	{
		for(int j=1;j<c[i];j++)
		{
			if(c[j]==c[i])
			for(int k=c[j];k<=c[i];k++)
			{
				c[k]=0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==aaa) {
			cout<<aaa<<" ";
			break;
		}
	}
	ccc++;
	}
	return 0;
}
