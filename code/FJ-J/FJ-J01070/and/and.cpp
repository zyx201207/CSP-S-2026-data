#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],maxx;
void dfs(int pre,int num,int st)
{
	if(pre==m)
	{
		maxx=max(num,maxx);
		return ;
	}
	for(int i=st+1;i<=n-m+pre+1;i++)
	{
		dfs(pre+1,num&a[i],i);
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
	for(int i=1;i<=n-m+1;i++)
	{
		dfs(1,a[i],i);
	}
	cout<<maxx;
	return 0;
 }
