#include<bits/stdc++.h>
using namespace std;
long long a[2000002];
long long c,t;
long long n,m;
vector<long long> edge[2000002];
long long dist[2000002];
long long cnt[2000002];
long long q[2000002];
bool b[2000002];
const int N=0x3f3f3f3f;
void work(int s,int t)
{
	for(int i=1;i<=n;i++)
	{
		dist[i]=0x3f3f3f3f;
		b[i]=false;
		q[i]=0;
	}
	dist[s]=0;
	cnt[s]=1;
	q[1]=s;
	long long rear=1;
	long long front=1;
	b[s]=true;
	while(front<=rear)
	{
		int x=q[front];
		front++;
		b[x]=false;
		for(auto y : edge[x])
		{
			if(dist[x]+1==dist[y])
			{
				cnt[y]+=cnt[x];
			}
			if(dist[x]+1<dist[y])
			{
				dist[y]=dist[x]+1;
				cnt[y]=cnt[x];
				if(!b[y])
				{
					q[++rear]=y;
					b[y]=true;
				}
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cnt[i]=0;
			edge[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=m)
				{
					edge[i].push_back(j);
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			work(i,n);
			for(int i=1;i<=n;i++)
			{
				if(cnt[i]==2)
				{
					ans++;
				}
			}	
		}
		cout<<ans;
	}
}
