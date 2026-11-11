#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-1;
bool vis[200005];
void dfs(long long now,long long pos)
{
	cout<<now<<" "<<pos<<endl;
	if(now<ans)return ; 
	if(pos==m)
	{
		ans=max(now,ans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(pos==0)
			{
				vis[i]=1;
				dfs(a[i],pos+1);
				vis[i]=0;
			}
			else
			{
				vis[i]=1;
				dfs(now&a[i],pos+1);
				vis[i]=0;
			}
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0);
	cout<<ans;
	return 0;
}
