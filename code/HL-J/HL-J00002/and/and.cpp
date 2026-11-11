#include<bits/stdc++.h>
using namespace std;
int n,m,a[900000],maxx=-100,sum;
void dfs(int deep,int sum)
{
	if(deep==m)
	{
		if(maxx<sum)
		{
			maxx=sum;
		}
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(deep==0) 
		{
			dfs(deep+1,a[i]);
		}
		else
		{
			dfs(deep+1,sum&a[i]);
		}
	} 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	dfs(0,0);
	cout<<maxx;
}
