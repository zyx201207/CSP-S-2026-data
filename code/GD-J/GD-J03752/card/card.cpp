#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int a[maxn],b[maxn],ans[maxn];
int n,m;
void checkcard(int p,int q)
{
	for(int i=0;i<p;i++)
	{
		if(b[i]==a[q])
		{
			for(int j=i+1;j<=p;j++)
			{
				b[j]=0;
			}
		}
	}
	return;
} 
void cardgame(int u)
{
	for(int i=0;i<n*(n+1)/2;i++)
	{
		b[i]=0;
	}
	for(int i=0;i<n-u+1;i++)
	{
		b[i]=a[u+i-1];
		checkcard(i,u+i-1);
	}
	for(int i=0;i<=n*(n+1)/2;i++)
	{
		ans[b[i]]++;
	}
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cardgame(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
