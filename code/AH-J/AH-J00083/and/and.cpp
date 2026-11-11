#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int f[200005],mx,sum=2147483647;
void dfs(int x,int y)
{
	if(y>=m)
	{
		mx=max(mx,sum);
		return;
	}
	else if(x>n)
		return;

	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			int oldsum=sum;
			sum&=a[i];
			f[i]=1;
			dfs(x+1,y+1);
			sum=oldsum;
			f[i]=0;
		}
	}
	dfs(x+1,y);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int k=a[i]&a[j];
					mx=max(k,mx);
			}
		}
		cout<<mx;
		return 0;
	}
	else if(m==n)
	{
		for(int i=1;i<=n;i++)
			sum&=a[i];
		cout<<sum;
		return 0;
	}
	else
	{
		dfs(1,0);
		cout<<mx;
	}
	return 0;
}
