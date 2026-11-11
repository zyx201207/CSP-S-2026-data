#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans[500010],maxx=-1e9;
bool vis[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	for(int u=1;u<=n;u++)
	{
		bool flag=true,sum;
		for(int i=0;i<=maxx;i++)vis[i]=false;
		for(int i=1;i<u;i++)vis[a[i]]=true;
		for(int i=u;i<=n;i++)
		{
			if(a[i]==m)
			{
				if(flag)flag=false,sum=i;
				else
				{
					for(int j=sum;j<i;j++)vis[a[j]]=true;
					sum=i;
				}
			}
				
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[a[i]])ans[a[i]]++,vis[a[i]]=true;
			//cout<<a[i]<<" :"<<ans[a[i]]<<endl;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
