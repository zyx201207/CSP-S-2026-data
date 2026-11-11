#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[200005],r[100005],a[505][2],t[505][2];
int ans;
void dfs(int s,int e,int step)
{
	if(s==e)
	{
		if(step>ans)
		{
			ans=step;
		}
		return ;
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i][1]==s)
		{
			dfs(a[i][2],e,step+t[i][1]);
		}
		if(a[i][2]==s)
		{
			dfs(a[i][1],e,step+t[i][2]);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	bool f=0;
	for(int i=1;i<=m;i++)
	{
		int h;
		cin>>h;
		if(h>2)
		{
			f=1;
		}
		cin>>a[i][1]>>t[i][1]>>a[i][2]>>t[i][2];
	}

	for(int i=1;i<=q;i++)
	{
		int s,e;
		cin>>s>>e;
		if(f==0)
		{	
			ans=0;
			dfs(s,e,0);
			cout<<ans+w[s]+w[e];
		}
		else
		{
			cout<<0;
		}
	}
}
