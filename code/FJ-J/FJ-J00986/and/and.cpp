#include<bits/stdc++.h>
using namespace std;
long long a[200100],ans=0,n,m;
bool b[200100];
void dfs(long long x,long long y)
{
	if(y==m)
	{
		ans=max(ans,x);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			int z=a[i]&x;
			
			if(y!=0)dfs(z,y+1);
			else dfs(a[i],y+1);
			b[i]=0; 
		}
	}
	return;
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
		dfs(0,0);
		
	    cout<<ans;
	return 0;
}
