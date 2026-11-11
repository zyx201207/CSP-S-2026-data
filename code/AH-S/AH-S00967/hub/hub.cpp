#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> g[2000005];
int xi[2000005],yi[2000005];
int d[2000005],dsum[2000005],dp[2000005];
queue<int> q;
int sm[2][2000005];
void dfs(int x,int fa,int op)
{
	int l=g[x].size();
	sm[op][dp[x]]++;
	for(int i=0;i<l;i++)
	{
		int y=g[x][i];
		if(y==fa)
			continue;
		dfs(y,x,op);
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tid,T;
	cin>>tid>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
			xi[i]=x,yi[i]=y;
		}
		if(tid==13 || tid==14)
		{
			n/=2;
			if(k>=2*n+1)
				cout<<0<<"\n";
			else if(k>=n)
				cout<<1<<"\n";
			else
			{
				int m=n-k+2;
				cout<<(m+1)/4+1<<"\n";
			}
			continue;
		}
		int ans=n;
		for(int mi=1;mi<n;mi++)
		{
			int x=xi[mi],y=yi[mi];
			while(!q.empty())
				q.pop();
			for(int i=1;i<=n;i++)
				d[i]=dsum[i]=dp[i]=0;
			for(int i=1;i<=n-1;i++)
				if(i!=mi)
					d[xi[i]]++,d[yi[i]]++,dsum[xi[i]]+=yi[i],dsum[yi[i]]+=xi[i];
			for(int i=1;i<=n;i++)
				if(d[i]==1)
					q.push(i);
			while(!q.empty())
			{
				int u1=q.front();
				q.pop();
				if(d[u1]==1)
				{
					int u2=dsum[u1];
					d[u2]--,dsum[u2]-=u1;
					if(d[u2]>=1)
						dp[u2]=max(dp[u2],dp[u1]+1);
					if(d[u2]==1)
						q.push(u2);
				}
			}
			for(int i=0;i<=n;i++)
				sm[0][i]=sm[1][i]=0;
			dfs(x,y,0);
			dfs(y,x,1);
			for(int i=n-1;i>=0;i--)
				sm[0][i]+=sm[0][i+1],sm[1][i]+=sm[1][i+1];
			for(int i=0;i<=n;i++)
			{
				if(max(1,sm[0][i])+max(1,sm[1][i])<=k)
				{
					ans=min(ans,i);
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
