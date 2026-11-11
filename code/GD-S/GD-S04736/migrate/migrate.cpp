#include<bits/stdc++.h>
using namespace std;
int c,T,vis[2000005],lu[2000005];
int n,d;
long long a[2000005];
void bfs(int bj)
{
	memset(vis,-1,sizeof vis);
	memset(lu,0,sizeof lu);
	queue<int> q,s;
	q.push(bj);s.push(0);
	while(!q.empty())
	{
		int k=q.front(),ti=s.front();
		if(vis[k]==-1) lu[k]=ti,vis[k]=1;
		else vis[k]++;
		q.pop();s.pop();
		for(int i=k+1;i<=n;i++)
		{
			if(a[i]-a[k]<=d) 
			{
				if(!lu[i]||(lu[i]==ti+1))
				{
				q.push(i);
				s.push(ti+1);	
				}
				if(lu[i]<ti+1) continue;
				vis[i]=-1;
				q.push(i);
				s.push(ti+1);
			}
			else break;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++)
		{
			bfs(i);
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==3) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
