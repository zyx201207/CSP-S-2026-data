#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn=-1;
void dfs(int num,long long sum,int l)
{
	if(l>n+1)	return;
	if(num==m)
	{
		maxn=max(maxn,sum);
		return;
	}
	if(!num)	dfs(num+1,a[l],l+1);
	else   dfs(num+1,sum&a[l],l+1);
	dfs(num,sum,l+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)	cin >> a[i];
	if(n<=20)	dfs(0,0,1);
	else if(m==1)
	{
		for (int i = 1;i <= n;i++)	maxn=max(maxn,a[i]);
	}
	else if(m==2)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				maxn=max(a[i]&a[j],maxn);
			}
		}
	}
	else if(m==n)
	{
		maxn=a[1];
		for (int i = 2;i <= n;i++)	maxn=maxn&a[i];
	}
	else if(m==n-1)
	{
		for (int i = 1;i <= n;i++)
		{
			long long sum=a[1],l=2;
			if(i==1)	
			{
				sum=a[2];
				l=3;
			}
			for (int j = l;j <= n;j++)
			{
				if(i!=j)	sum&=a[j];
			}
			maxn=max(maxn,sum);
		}
	}
	else
	{
		int f=1;
		for (int i = 1;i <= n;i++)	if(a[i]!=i-1){f=0;break;}
		if(f)
		{
			long long k=0,sum=1;
			while(sum<n)
			{
				sum*=2;
				k++;
			}
			for (int i = 1;i <= m-1;i++)
			{
				sum/=2;
			}
			maxn=sum;
		}
		else
		{
			sort(a+1,a+n+1);
			maxn=a[n-m+1];
		}
	}
	cout << maxn;
	return 0;
}
