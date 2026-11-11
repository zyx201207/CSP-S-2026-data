#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
bool b[200005];
long long ans;
void dfs(int g,long long sum1)
{
	if(g>m)
	{
		ans=max(sum1,ans);	
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			g+=1;
			dfs(g,sum1&a[i]);
			g-=1;
			b[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long max1=0;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]>max1)
			{
				max1=a[i];
			}
		}
		cout<<max1;	
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,32767);
	cout<<ans;
	return 0;
}
