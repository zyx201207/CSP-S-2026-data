#include<bits/stdc++.h>
using namespace std;
int n,m,a[25],ans=-1;
void dfs(int k,int s,int i)
{
	if(k>m)
	{
		ans=max(ans,s);
		return;
	}
	if(i>n)
	{
		
	}
	dfs(k+1,s&a[i],i+1);
	dfs(k,s,i+1);
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
	dfs(1,a[1],1);
	cout<<ans<<"\n";
	return 0;	
} 
