#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],vis[200010],ans[200010],q;
void dfs(long long x,long long dep,long long y)
{
	if(dep==m+1)
	{
		q=max(x,q);
		return;
	}
	for(int i=y+1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			x=max(q,x&a[i]);
			dfs(x,dep+1,y);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(a[i],1,i);
	}
	cout<<q<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
} 
