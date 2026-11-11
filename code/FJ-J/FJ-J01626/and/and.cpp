#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=INT_MIN,a[200020],c[200020];
void dfs(int k,int an, int o)
{
	if(k==m)
	{
		maxx=max(maxx,an);
		return ;
	}
	else
	{
		for(int i=o;i<=n;i++)
		{
			if((an&a[i])!=0)dfs(k+1,an&a[i],i+1);
		}
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
		cin>>a[i];
	}
	dfs(0,int(pow(2,31)),1);
	cout<<maxx;
	return 0;
 } 
