#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+5;
const long long inf=1e18;
int CC,n,m,d,Q;
long long w[N];
int len[505];
vector<int> s[505];
vector<long long> cost[505];
long long a[505][505];
pair<int,long long> D[N][25];
int cnt[N];
int main()
{
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>CC>>n>>m>>d>>Q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=inf;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>len[i];
		s[i].push_back(0);
		cost[i].push_back(0);
		for(int j=1;j<=len[i];j++)
		{
			int x,y;
			cin>>x>>y;
			s[i].push_back(x);
			cost[i].push_back(y);
			D[s[i][j]][++cnt[s[i][j]]]=make_pair(i,cost[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=len[i];j++)
		{
			int now=s[i][j],u=i;
			for(int k=1;k<=cnt[now];k++)
			{
				int v=D[now][k].first;
				long long w=D[now][k].second;
				if(v==u) continue;
				a[u][v]=min(a[u][v],cost[i][j]+w);
				a[v][u]=min(a[v][u],cost[i][j]+w);
			}
		}
		a[i][i]=0;
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<a[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=1;j<=n;j++)
			{
				if(j==k||j==i) continue;
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(int tt=1,st,en;tt<=Q;tt++)
	{
		cin>>st>>en;
		long long ans=inf;
		for(int i=1;i<=cnt[st];i++)
		{
			int u=D[st][i].first;
			long long w1=D[st][i].second;
			for(int j=1;j<=cnt[en];j++)
			{
				int v=D[en][j].first;
				long long w2=D[en][j].second;
				ans=min(ans,a[u][v]+w1+w2);
//				cout<<"|||"<<u<<' '<<v<<' '<<w1<<' '<<w2<<' '<<a[i][j]<<endl;
			}
		}
//		cout<<ans<<' '<<w[st]<<' '<<w[en]<<endl; 
		cout<<ans+w[st]+w[en]<<endl;
//		chk[tt]=ans+w[st]+w[en];
	}
//	fclose(stdin);
//	freopen("subway7.ans","r",stdin);
//	bool AC=1;
//	for(int i=1;i<=Q;i++)
//	{
//		long long x;
//		cin>>x;
//		if(x!=chk[i])
//		{
//			AC=0;
//			cout<<"Wrong answer on test "<<i<<" read "<<chk[i]<<" expected "<<x<<endl;
//		}
//	}
//	if(AC) cout<<"OK Accepted!"<<endl;
	return 0;
}
