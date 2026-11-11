#include<bits/stdc++.h>
using namespace std;

int n,m;
long long ans,c=0;
int vc[200100],mp[200100];
void dfs(int x=1)
{
	if(x>m)
	{
		ans=max(ans,c);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[i]==0)
		{
			if(x==1)	c=vc[i],mp[i]=1,dfs(x+1),mp[i]=1,c=0;
			else{
				int p=c;c&=vc[i],mp[i]=1,dfs(x+1),mp[i]=0,c=p;
			}
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
		cin>>vc[i];
	}
	dfs();
	cout<<ans;
	return 0;
}
/*
*/
