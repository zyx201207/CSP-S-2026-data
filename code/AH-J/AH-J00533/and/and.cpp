#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,s,s1,a[200005],s2,maxn,tsa,tsb;
bool cmp(int a,int b) 
{
	return a>b;
}
void dfs(int st,int ma,int gs)
{
	if(gs==m) 
	{
		maxn=max(ma,maxn);
		return ;
	}
	if(st>n) return ;
	if(ma*2<maxn) return ;
	if(ma!=0) dfs(st+1,ma&a[st],gs+1);
	else dfs(st+1,a[st],gs+1);
	dfs(st+1,ma,gs);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i-1) tsb=1;
		if(a[i]%2==0) tsa=1;
		s=max(s,a[i]);
		if(i==1) s1=a[i];
		else s1=s1&a[i];
	}
	if(m==1)
	{
		cout<<s;
	}
	else if(m==n)
	{
		cout<<s1;
	}
	else if(m==2)
	{
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				s2=max(s2,a[i]&a[j]);
			}
		}
		cout<<s2;
	}
	else if(tsa==0)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	else if(tsb==0)
	{
		sort(a+1,a+n+1,cmp);
		int yu=a[1];
		for(i=2;i<=m;i++)
		{
			yu=yu&a[i];
		}
		cout<<yu;
	}
	else if(n<20)
	{
		dfs(1,0,0);
		cout<<maxn;
	}
}
