#include<bits/stdc++.h>
using namespace std;
long long a[200100],ans,n,m;
bool Used[200100];
void dfs(int s,long long sum)
{
	if(s==m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(Used[i]==0)
		{
			Used[i]=1;
			dfs(s+1,sum&a[i]);
			Used[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,(1<<64)-1);
	cout<<ans<<endl;	
	return 0;
}

