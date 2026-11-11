#include<bits/stdc++.h> 
using namespace std;
int n,m,a[200005];
long long ans=0;
void dfs(int x,long long s,int f)
{
	if(x>n)
	  return ;
	if(f==m)
	{
		if(s>=ans)
		  ans=s;
		return ;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(s==0)
		{
			dfs(i,a[i],f+1);
		}
		else
		  dfs(i,s&a[i],f+1);
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
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
