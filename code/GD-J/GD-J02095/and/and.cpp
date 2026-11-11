#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
int vis[maxn];
int a[maxn];
int Max=-1;
int sum()
{
	int cnt=0;
	int s=pow(2,31)-1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			cnt++;
			if(s==pow(2,31)-1)
			{
				s=a[i];
			}
			else
			{
				s&=a[i];
			}
		}
	}
	if(cnt==m)
	{
		return s;
	}
	else
	{
		return -1;
	}
}
void dfs(int cur)
{
	if(cur==n+1)
	{
		Max=max(Max,sum());
		return ;
	}
	vis[cur]=0;
	dfs(cur+1);
	vis[cur]=1;
	dfs(cur+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<Max<<endl;
	return 0;
}
