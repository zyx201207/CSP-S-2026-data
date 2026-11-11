#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool vis[200005];
long long maxn=-1;
void dfs(int step,long long sum)
{
	if(step>m)
	{
		maxn=sum;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&sum>maxn)
		{
			
			vis[i]=1;
			dfs(step+1,sum&a[i]);					
		   vis[i]=0;
		}
	}
}
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(1,2147483648-1);
	cout<<maxn;
	return 0;
}
