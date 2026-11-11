#include<bits/stdc++.h> 
using namespace std;
int x[200500],maxn=-1;
int n,m;
void dfs(int a,int p,int ans)
{
	if(p==m)
	{
		maxn=max(maxn,ans);
		return ;
	}
	int y=ans&x[a];
	if(ans==0)
	y=x[a];
	if(a+1<=n)
	{
		dfs(a+1,p+1,y);
		dfs(a+1,p,ans);
	}
	
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	if(n<=25)
	{	
		dfs(1,0,0);
	}	
	else
	{
			if(m==1)
			{
				for(int i=1;i<=n;i++)
				{
					maxn=max(maxn,x[i]);
				}	
			}
			else
			{
				sort(x+1,x+1+n);
				int y=x[n]; 
				for(int i=n;i>=n-m+1;i++)
				{
					y=y&x[i];
				}
				maxn=y;
			}
	}
	cout<<maxn;
	return 0;
}

