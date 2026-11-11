#include <bits/stdc++.h>
using namespace std;
long long a[200005],f[200005],n,m,s;
void kd(int k,int c,int o)
{
	for(int i=k;i>k-c;i--)
	{
		a[i]=a[i]-o;
	}
	sort(a+1,a+k+1);
}
void qc(int k,int c,int o)
{
	for(int i=1;i<=c;i++)
	{
		a[i]=a[k-c+i]-o;
	}
}
void dfs(int o,int k)
{
	if(o==0)
	{
		return ;
	}
	int c=0;
	for(int i=k;i>=1;i--)
	{
		if(a[i]>=o)
		{
			c++;
		}
		else
		{
			break;
		}
	}
	if(c>=m)
	{
		s=s+o;
		qc(k,c,o);
		dfs(o/2,c);
	}
	else
	{
		kd(k,c,o);
		dfs(o/2,k);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int o=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(o<a[i])
		{
			while(o<a[i])
			{
				if(o*2>a[i])
				{
					break;
				}
				o=o*2;
			}
		}
	}
	sort(a+1,a+n+1);
	dfs(o,n);
	cout<<s;
}
