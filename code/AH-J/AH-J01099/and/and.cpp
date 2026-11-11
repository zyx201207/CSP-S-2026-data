#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],f[100005],l=0,sum,t=0,maxn=INT_MIN;
void dfs(int c,int x)
{
	if (x==1)
	{
		l++;
		f[c]=1;
		if (l==m)
		{
			for (int i=1;i<=n;i++)
			{
				if (f[i]==1)
				{
					if (t==0)
					{
						sum=a[i];
					}
					else
					{
						sum=sum&a[i];
					}
				}
			}
			maxn=max(maxn,sum);
			for (int i=1;i<=n;i++)
			{
				f[i]=0;
			}
			t=0;
			sum=0;
		}
	}
	else if (c!=n)
	{	
		dfs(++c,0);
		c--;
		
		dfs(++c,1);
	}	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,1);
	dfs(1,0);
	cout<<maxn;
	return 0;
}
