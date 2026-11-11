#include <bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[200005];
void dfs(int u,int len,int ans)
{
	if(len==m)
	{
		maxn=max(maxn,ans);
		return ;
	}
	for(int i=u+1;i<=n;i++)
	{
	
		
		dfs(i,len+1,ans & a[i]);	
		 
		
	}
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dfs(i,1,a[i]);
		
	}
	cout<<maxn;
	return 0;
	fclose(stdin);
 	fclose(stdout);
}
