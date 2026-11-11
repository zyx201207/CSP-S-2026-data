#include<bits/stdc++.h>
using namespace std;
#define ui unsigned int
int n,m,ans=0;
bool vis[10005];
int a[10005];
void dfs(int re,int curr)
{
	if(re==0) ans=max(ans,curr);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(re-1,curr&a[i]);
			vis[i]=0;
		}
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
	dfs(m,pow(2,31)-1);
	cout<<ans;
	
	return 0;
}
