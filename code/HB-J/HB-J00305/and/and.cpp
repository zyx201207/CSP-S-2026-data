#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int maxx=-1;
void dfs(int g,int x,bool bo,int l)
{
	
	if(g==m)
	{
		maxx=max(maxx,x);
		return ;
	}
	for(int i=g;i<n;i++)
	{
		if(bo&&i!=l)
		{
			dfs(g+1,a[i],false,i);
		}
		else if(i!=l)
		{
			dfs(g+1,(a[i] & x),bo,i);
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	dfs(0,0,true,-1);
	cout<<maxx;
	return 0;
}

