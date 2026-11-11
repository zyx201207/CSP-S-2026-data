#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,cnt,cc=1,cb=1;
int a[N],b[N],c[N],t[N],tj[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cc=1;
		cb=1;
		for(int j=1;j<=m+10;j++)
		{
			t[j]=0;
		}
		for(int j=1;j<=n+10;j++)
		{
			b[j]=0;
			c[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]])
			{
				for(int k=t[a[j]];b[k]!=0;k++)
				{
					c[cc]=b[k];
					cc++;
					cb=t[a[j]]+1;
				}
			}
			else
			{
				b[cb]=a[j];
				cb++;
				t[a[j]]=cb-1;
			}
		}
		for(int i=1;i<=cb;i++)
		{
			tj[b[i]]++;
			c[cc]=b[i];
			cc++;
		}
		for(int i=1;i<=cc;i++)
		{
			a[i]=c[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tj[i]<<' ';
	}
	return 0;
}