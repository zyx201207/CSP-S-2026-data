#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,m,a[N],maxx,andd,maxxx,ans;
void dfs(int x,int y,int v)
{
	if(n-x+1<m-y)
		return;
	if(x>n)
	{
		if(y==m)
			ans=max(ans,v);
		return;
	}
	if(v==-1)
	{
		dfs(x+1,y+1,a[x]);
		dfs(x+1,y,-1);
	}
	else
	{
		dfs(x+1,y+1,v&a[x]);
		dfs(x+1,y,v);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<n;i++)
		andd=a[i]&a[i+1];
	sort(a+1,a+1+n);
	if(m==1)
		cout<<maxx;
	else if(m==n)
		cout<<andd;
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					continue;
				maxxx=max(maxxx,a[i]&a[j]);
			}
		}
		cout<<maxxx;
	}
	else
	{
		dfs(1,0,-1);
		cout<<ans;
	}
	return 0;
}
