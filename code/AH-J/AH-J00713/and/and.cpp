#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005],m,n,ans;
void dfs(int u,int s,int c)
{
	if(c==m)
	{
		ans=max(s,ans);
		return;
	}
	if(u>n||n-u+1<m-c)return;
	dfs(u+1,s&a[u],c+1);
	dfs(u+1,s,c);	
}
bool l2(int x)
{
	for(int i=30;i>=0;i--)
		if(1<<i==x)return 1;
	return 0;
}
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!l2(a[i]+1))f=0;
	}
	if(!f)dfs(1,(1<<30)-1,0);
	else
	{
		int s=1<<30;s--;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++)s&=a[i];
		ans=s;
	}
	cout<<ans;
	return 0;
}
