#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M=5e5+5,N=5e2+5;

struct edge
{
	int y,z;
	bool operator < (const edge &X)const 
	{
		return z>X.z;
	}
};

int c,n,m,d,q,w[M],pre[N],dp[N][N];
vector<int>a[N],t[N],ve[M],ves[M];
unordered_map<int,int>mp[M];
vector<edge>vec[N];

void solve(int x,int y)
{
	int ans=LLONG_MAX;
	for(int i=0,lenx=ve[x].size();i<lenx;++i)
	{
		for(int j=0,leny=ve[y].size();j<leny;++j)
		{
			ans=min(ans,dp[ve[x][i]][ve[y][j]]+ves[x][i]+ves[y][j]);
		}
	}
	cout<<ans+w[x]+w[y]<<'\n';
	return ;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	auto itt=mp[0][-1];
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		a[i].assign(k+1,0);
		t[i].assign(k+1,0);
		for(int j=1;j<=k;++j)
		{
			cin>>a[i][j]>>t[i][j];
			ve[a[i][j]].push_back(i);
			ves[a[i][j]].push_back(t[i][j]);
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=0,len=ve[i].size();j<len;++j)
		{
			for(int xy=j+1;xy<len;++xy)
			{
			    auto it=mp[ve[i][j]][ve[i][xy]];
				if(it==itt||(it!=itt&&ves[i][j]+ves[i][xy]<mp[ve[i][j]][ve[i][xy]]))
				{
					mp[ve[i][j]][ve[i][xy]]=ves[i][j]+ves[i][xy];
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(mp[i][j]==itt)continue;
			vec[i].push_back({j,mp[i][j]});
			vec[j].push_back({i,mp[i][j]});
		}
	}
	memset(dp,0x3f,sizeof dp);
	for(int now=1;now<=n;++now)
	{
		priority_queue<edge>qu;
		qu.push({now,0});
		dp[now][now]=0;
		while(qu.size())
		{
			edge x=qu.top();
			qu.pop();
			if(dp[now][x.y]!=x.z)continue;
			for(int I=0,len=vec[x.y].size();I<len;++I)
			{
				edge i=vec[x.y][I];
				if(dp[now][i.y]>x.z+i.z)
				{
					dp[now][i.y]=x.z+i.z;
					qu.push({i.y,dp[now][i.y]});
				}
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
 } 
