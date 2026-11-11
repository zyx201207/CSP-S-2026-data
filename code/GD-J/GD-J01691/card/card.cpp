#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[300005],num[300005],k1,k,x,l,d[500005];
queue<long long> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	k=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(c[a[i]]==0)
		{
			c[a[i]]=i;
		}
		else
		{
			b[i]=c[a[i]];
			c[a[i]]=i;
			q.push(i);
			k++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		k1=0;
		for(int j=1;j<=k;j++)
		{
			x=q.front();
			q.pop();
			if(b[x]>=i)
			{
				if(d[b[x]]>=0)
				{
					for(int r=b[x];r<x;r++)
					{
						d[r]=-1;
					}
				}
				q.push(x);
				k1++;
			}
		}
		k=k1;
		for(int j=i;j<=n;j++)
		{
			if(d[j]!=-1)
			{
				num[a[j]]++;
			} 
		}
		for(int j=1;j<=n;j++)
		{
			d[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
