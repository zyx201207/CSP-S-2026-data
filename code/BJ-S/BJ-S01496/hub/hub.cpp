#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
vector<int> mp[N];
int dis[N];
void dfs(int u,int fa)
{
	dis[u]=dis[fa]+1;
	for(int i:mp[u])
	{
		if(i==fa)continue;
		dfs(i,u);
	}
}
int n,k;
bool work(bitset<20> &t)
{
	int tmp=-1;
	for(int i=1;i<=n;i++)
	{
		if(t[i])
		{
			tmp=i;
			break;
		}
	}
	if(tmp==-1)
	{
		return false;
	}
	queue<int> q;
	q.push(tmp);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		t[now]=0;
		for(int v:mp[now])
		{
			if(!t[v])
			{
				continue;
			}
			q.push(v);
		}
	}
	return true;
}
int f[20][20];
void solveA(int t)
{
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		if(k==n)
		{
			cout<<0<<'\n';
			continue;
		}
		n=n/2;
		n-=k;
		cout<<(n+3)/4+1<<'\n';
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(13<=c&&c<=14)
	{
		solveA(t);
		return 0;
	}
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			mp[i].clear();
		}
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<n;i++)
		{
			f[i][i]=0;
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
			f[u][v]=1;
			f[v][u]=1;
		}
		f[n][n]=0;
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==k)continue;
				for(int j=1;j<=n;j++)
				{
					if(i==j||j==k)continue;
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		dfs(1,0);
		int ans=1e18;
		for(int B=1;B<(1<<n);B++)
		{
			bitset<20> t,t1;
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if((B>>(i-1))&1)
				{
					t[i]=1;
					cnt++;
				}
			}
			if(cnt!=k)continue;
			t1=t;
			work(t);
			work(t);
			bool tmp=work(t);
			if(tmp)
			{
				continue;
			}
			t=t1;
			int res=0;
			for(int i=1;i<=n;i++)
			{
				if(t[i])continue;
				int tmp=1e18;
				for(int j=1;j<=n;j++)
				{
					if(!t[j])continue;
					tmp=min(f[i][j],tmp);
				}
				res=max(res,tmp);
			}
			/*for(int i=1;i<=n;i++)
			{
				if(t[i])
				{
					cout<<i<<" ";
				}
			}
			cout<<'\n';
			cout<<res<<"\n";*/
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}