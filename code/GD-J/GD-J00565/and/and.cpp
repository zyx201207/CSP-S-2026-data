#include<bits/stdc++.h>
using namespace std;
long long c[2001];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) 
	{
		cin>>c[i];
	}
	if(m==2)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(j==i){continue;}
				maxn=max(maxn,c[i]&c[j]);
			}
		}
	}
	if(m==3)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					if(j==i){continue;}
					if(j==k){continue;}
					if(i==k){continue;}
					maxn=max(maxn,c[i]&c[j]&c[k]);
				}
			}
		}
	}
	if(m==4)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					for(int l=0;l<=n;l++)
					{
						if(j==i){continue;}
						if(j==k){continue;}
						if(i==k){continue;}
						if(j==l){continue;}
						if(i==l){continue;}
						if(k==l){continue;}
						maxn=max(maxn,c[i]&c[j]&c[k]&c[l]);
					}
				}
			}
		}
	}
	if(m==5)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					for(int l=0;l<=n;l++)
					{
						for(int p=0;p<=n;p++)
						{
							if(j==i){continue;}
							if(j==k){continue;}
							if(i==k){continue;}
							if(j==l){continue;}
							if(i==l){continue;}
							if(k==l){continue;}
							if(j==p){continue;}
							if(k==p){continue;}
							if(i==p){continue;}
							if(l==p){continue;}
							maxn=max(maxn,c[i]&c[j]&c[k]&c[l]&c[p]);
						}
					}
				}
			}
		}
	}
	if(m==6)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k=0;k<=n;k++)
				{
					for(int l=0;l<=n;l++)
					{
						for(int p=0;p<=n;p++)
						{
							for(int r=0;r<=n;r++)
							{
								if(j==i){continue;}
								if(j==k){continue;}
								if(i==k){continue;}
								if(j==l){continue;}
								if(i==l){continue;}
								if(k==l){continue;}
								if(j==p){continue;}
								if(k==p){continue;}
								if(i==p){continue;}
								if(l==p){continue;}
								if(i==r){continue;}
								if(j==r){continue;}
								if(k==r){continue;}
								if(l==r){continue;}
								if(p==r){continue;}
								maxn=max(maxn,c[i]&c[j]&c[k]&c[l]&c[p]&c[r]);
							}
						}
					}
				}
			}
		}
	}
	cout<<maxn;
}
