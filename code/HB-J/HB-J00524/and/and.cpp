#include <bits/stdc++.h>
using namespace std;
int a[200005],book[200005],num[200005];
int n,m,maxnn=0;
void one()
{
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,a[i]);
	}
	cout << maxn;
}
void two()
{
	int maxn=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout << maxn;
}
void three()
{
	int k=a[1];
	for(int i=2;i<=n;i++)
		k=k&a[i];
	cout << k;
}
void four()
{
	int on=0,tw=0,th=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1) on++;
		else if(a[i]==2) tw++;
		else if(a[i]==3) th++;
	}
	if(th>=m) 
	{
		cout << 3;
		return;
	}
	else if((th+on)>=m) 
	{
		cout << 1;
		return;
	}
	cout << 0;
	return ;
}
void dfs(int x)
{
	if(x==m+1)
	{
		int k=a[num[1]];
		for(int i=2;i<=m;i++)
		{
			k=k&a[num[i]];
		}
		maxnn=max(maxnn,k);
	}	
	for(int i=1;i<=n;i++)
	{
		if(!book[i])
		{
			num[x]=i;
			book[i]=1;
			dfs(x+1);
			book[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int nmax=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		nmax=max(nmax,a[i]);
	}
	if(m==1)
	{
		one();
		return 0;
	}
	else if(m==2)
	{
		two();
		return 0;
	}
	else if(n==m)
	{
		three();
		return 0;
	}
	else if(nmax<4)
	{
		four();
		return 0;
	}
	dfs(1);
	cout << maxnn;
	return 0;
}
//O(n) ~ O(2^n)
