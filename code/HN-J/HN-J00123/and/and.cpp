#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,ma;
void dfs(int id,int x,int s)
{
	if(x==m)
	{
		ans=max(ans,s);
		return;
	}
	if(id==n&&x<m)
	{
		return;
	}
	if(x==0)
	{
		dfs(id+1,x+1,a[id]);
	}
	else
	{
		dfs(id+1,x+1,s&a[id]);
	}
	dfs(id+1,x,s);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1)
	{
		cout<<ma;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
