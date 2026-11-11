#include <bits/stdc++.h>
using namespace std;
int n,m;
int b;
int maxn=-1e9;
int a[200010];
void dfs(int l,int gs,int jg)
{
	if(l+1==n)
	{
		if(gs==m)
		{
			maxn=max(maxn,jg);
		}
	}
	else
	{
		dfs(l+1,gs,jg);
		b=jg;
		dfs(l+1,gs+1,jg&a[l]);
		l-=1,gs-=1,jg=b;
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
	dfs(1,0,a[1]);
	cout<<maxn;
	return 0;
} 
