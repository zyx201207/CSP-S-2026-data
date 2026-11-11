#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,t;
int n,k;
vector<int> e[N];

namespace BF{
	int dis[20][20];
	int fa[N],dep[N];
	void dfs(int x)
	{
		for(int i:e[x])
		{
			if(i==fa[x]) continue;
			dep[i]=dep[x]+1;
			fa[i]=x;
			dfs(i);
		}
	}
	int solve()
	{
		for(int i=1;i<=n;i++)
		{
			dep[i]=0,fa[i]=0;
			dfs(i);
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=dep[j];
			}
		}
		int ans=1e9;
		for(int i=1;i<(1<<n);i++)
		{
			if(__builtin_popcount(i)==k)
			{
				int cnt=k;
				for(int x=1;x<=n;x++)
				{
					for(int y:e[x])
					{
						if(y>x && i&(1<<x-1) && i&(1<<y-1)) cnt--;
					}
				}
				if(cnt>2) continue;
				int tmp=0;
				for(int x=1;x<=n;x++)
				{
					int d=1e9;
					for(int y=1;y<=n;y++)
					{
						if(i&(1<<y-1)) d=min(d,dis[y][x]);
					}
					tmp=max(tmp,d);
				}
				ans=min(ans,tmp);
			}
		}
		return ans;
	}
}

namespace BF1{
	int dis[1010][1010];
	int fa[N],dep[N];
	int mxd[N];
	int dfn[N],totdfn;
	int siz[N];
	void dfs(int x)
	{
		dfn[x]=++totdfn;
		mxd[x]=0;
		siz[x]=1;
		for(int i:e[x])
		{
			if(i==fa[x]) continue;
			dep[i]=dep[x]+1;
			fa[i]=x;
			dfs(i);
			mxd[x]=max(mxd[x],mxd[i]+1);
			siz[x]+=siz[i];
		}
	}
	int cnt[N];
	int solve()
	{
		for(int i=1;i<=n;i++)
		{
			dep[i]=0,fa[i]=0;
			dfs(i);
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=dep[j];
			}
		}
		int K=k;
		int ans=1e9;
		for(int i=1;i<=n;i++)
		{
			totdfn=0;
			dep[i]=fa[i]=0;
			dfs(i);
			for(int j=i+1;j<=n;j++)
			{
				if(K==2)
				{
					int tmp=0;
					for(int l=1;l<=n;l++)
					{
						tmp=max(tmp,min(dis[i][l],dis[j][l]));
					}
					ans=min(ans,tmp);
					continue;
				}
				int p=j;
				while(fa[p]!=i) p=fa[p];
				for(int k=0;k<=n;k++) cnt[k]=0;
				int tmp=0;
				for(int k=1;k<=n;k++)
				{
					if(k==i || k==j) continue;
					if(dfn[k]>=dfn[p] && dfn[k]<dfn[p]+siz[p])
					{
						if(dfn[k]>=dfn[j] && dfn[k]<dfn[j]+siz[j])
						{
							cnt[mxd[k]]++;
						}
						else
						{
							tmp=max(tmp,min(dis[i][k],dis[j][k]));
						}
					}
					else
					{
						cnt[mxd[k]]++;
					}
				}
				int sum=0;
				for(int i=n;i>=tmp;i--)
				{
					sum+=cnt[i];
					if(sum>K-2) break;
					ans=min(ans,i);
				}
			}
		}
		return ans;
	}
}

namespace sol1{
	int solve()
	{
		int m=n/2;
		if(k==n) return 0;
		if(k>=m) return 1;
		for(int i=2;i<=n;i++)
		{
			if(4*(i-1)+k>=m) return i;
		}
		return n+1;
	}
}
//13,14

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		for(int i=1;i<=n;i++) e[i].clear();
		cin>>n>>k;
//		cerr<<t<<" "<<n<<" "<<k<<"\n";
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if(n<=10 && c<=3)
		{
			int ans=BF::solve();
			int ans1=BF1::solve();
			cout<<ans<<"\n";
			continue;
		}
		if(c<=8)
		{
			int ans=BF1::solve();
			cout<<ans<<"\n";
			continue;
		}
		if(c>=13 && c<=14)
		{
			int ans=sol1::solve();
			cout<<ans<<"\n";
			continue; 
		}
	}
}
/*
g++ hub.cpp -o hub -O2 -std=c++14 -static
./hub

16:15 start BF(O(n^2))
-----
16:56 thinking
	BF 2^n枚举集合。1、判定是否最多两个联通快；2、多源BFS。
	k=2,O(n^3)：getdis，暴力枚举。
	O(n^3) ，枚举两个点x,y——路径内的点暴力加入贡献，路径外的看情况。 
*/
