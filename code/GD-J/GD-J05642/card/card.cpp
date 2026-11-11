#include <iostream>
#include <queue>
using namespace std;
bool f[1000];
int ans[200010],n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n>=500&&m>=200)
	{
	
		int a[200010];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
					f[a[j]]=0;
			}
			for(int j=i;j<=n;j++)
			{
				if(f[a[j]]==0)
				{
					f[a[j]]=1;
					ans[a[j]]++;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
	}
		if(n<=500&&m<=200)
	{
		int a[1000];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			queue<int>q;
			for(int j=i;j<=n;j++)
			{
				f[a[j]]=0;
			}
			for(int j=i;j<=n;j++)
			{
				if(f[a[j]]==0)
				{
					q.push(a[j]);
					f[a[j]]=1;
				}
				else
				{
					while(q.front()!=a[j])
					q.pop();
					
				}
			}
			while(!q.empty())
			{
				int x=q.front();
				cout<<x<<" ";
				q.pop();
				ans[x]++;
			}
			cout<<endl;
		for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
		cout<<endl;
		}
		for(int i=1;i<=m;i++)
		{
		cout<<ans[i];
		}
	}
	return 0;
 } 
