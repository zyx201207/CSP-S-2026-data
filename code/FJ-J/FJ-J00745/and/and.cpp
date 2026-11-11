#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9' || ch<'0')
	{
		if(ch=='-')
		{
			ch=getchar();
			f=-f;
		}
	}
	while(ch<='9' && ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	int maxn=INT_MIN;
	for(int i=0;i<n;i++)
	{
		a[i]=read();
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
	}
	else if(m==2)
	{
		int maxnn=INT_MIN;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				maxnn=max(a[i]&a[j],maxnn); 
			}
		}
		cout<<maxnn;
	}
	else if(m==3)
	{
		int maxnn=INT_MIN;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=j+1;k<n;k++)
				{
					maxnn=max(a[i]&a[j]&a[k],maxnn);
				}
			}
		}
		cout<<maxnn;
	}
	else if(m==4)
	{
		int maxnn=INT_MIN;
		for(int u=0;u<n;u++)
		{
			for(int i=u+1;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					for(int k=j+1;k<n;k++)
					{
						maxnn=max(a[i]&a[j]&a[k]&a[u],maxnn);
					}
				}
			}
		}
	}
	else if(m==5)
	{
		int maxnn=INT_MIN;
		for(int v=0;v<n;v++)
		{
			for(int u=v+1;u<n;u++)
			{
				for(int i=u+1;i<n;i++)
				{
					for(int j=i+1;j<n;j++)
					{
						for(int k=j+1;k<n;k++)
						{
							maxnn=max(a[i]&a[j]&a[k]&a[u],maxnn);
						}
					}
				}
			}
		}
	}
	return 0;
}
//good luck ^_^

