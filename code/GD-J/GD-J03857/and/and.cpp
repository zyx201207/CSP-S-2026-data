#include<bits/stdc++.h>
using namespace std;
long long maxm=-1,a[211111];
int n,m;
void dfs(int k,long long s,int l)
{
	
	if(k>m)
	{
		maxm=max(maxm,s);
		return ;
	}
	if(s<maxm)
		return ;
	for(int i=l+1;i<=n;i++)
		dfs(k+1,s&a[i],i);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,(1<<30)-1,0);
	cout<<maxm;
	return 0;
}
