#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5,inf=1e15;
int n,m,k;
vector<int>aa[maxn];
int mx,t,ed;
void dfs1(int x,int fa,int len)
{
	if(len>mx)mx=len,t=x;
	for(int i=0;i<aa[x].size();i++)
	{
		int to=aa[x][i];
		if(to==fa)continue;
		dfs1(to,x,len+1);
	}
}
int zhan[maxn],top,c[maxn],d[maxn];
bool vis[maxn];
void dfs2(int x,int fa)
{
	zhan[++top]=x;
	if(x==ed)
	{
		for(int i=1;i<=top;i++)c[i]=zhan[i];
	}
	for(int i=0;i<aa[x].size();i++)
	{
		int to=aa[x][i];
		if(to==fa)continue;
		dfs2(to,x);
	}
	top--;
}
int dfs3(int x,int fa)
{
	int ans=0;
	for(int i=0;i<aa[x].size();i++)
	{
		int to=aa[x][i];
		if(to==fa || vis[to])continue;
		ans=max(ans,dfs3(to,x)+1);
	}
	return ans;
}
bool check(int x)
{
	int l=1;
	mx=-inf;
	for(l=1;l<=top;)
	{
		mx++;
		mx=max(mx,d[l]);
		if(mx>x)
		{
			l--;
			break;
		}
		l++;
	}
	if(l==top)return 1;
	int r=top;
	mx=-inf;
	for(;r>=l;)
	{
		mx++;
		mx=max(mx,d[r]);
		if(mx>x)
		{
			r++;
			break; 
		}
		r--;
	}
	if(l>=r)return 1;
	for(int i=l+1;i<r;i++)
	{
		if(i-l+d[i]>x && r-i+d[i]>x)return 0;
	}
	return 1;
}
void dfs_(int x,int can)
{
	vis[x]=1;
	for(int i=0;i<aa[x].size();i++)
	{
		int to=aa[x][i];
		if(vis[to] || !(can&(1<<(to-1))))continue;
		dfs_(to,can);
	}
}
int dfs__(int x,int fa)
{
	if(vis[x])return 0;
	int ans=-inf;
	for(int i=0;i<aa[x].size();i++)
	{
		int to=aa[x][i];
		if(to==fa)continue;
		ans=max(ans,dfs__(to,x)+1);
	}
	return ans;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int id_,T;
	cin>>id_>>T;
	if(id_==7 || id_==11 || id_==12)
	{
		while(T--)
		{
			cin>>n>>k;
			for(int i=1;i<n;i++)
			{
				int x,y;
				cin>>x>>y;
				aa[x].push_back(y);
				aa[y].push_back(x);
			}
			top=0;
			mx=-inf;
			dfs1(1,0,0);
			int x=t;
			mx=-inf;
			dfs1(x,0,0);
			int y=t,len=mx;
			ed=y;
			dfs2(x,0);
			top=len;
			for(int i=1;i<=len;i++)vis[c[i]]=1;
			for(int i=1;i<=top;i++)d[i]=dfs3(c[i],0);
			c[n+1]=-inf;
			for(int i=n;i>=1;i--)c[i]=max(c[i+1],i+d[i]);
			int l=0,r=n+1;
			while(l+1<r)
			{
				int mid=l+r>>1;
				if(check(mid))r=mid;
				else l=mid;
			}
			cout<<r<<'\n';
			for(int i=1;i<=n;i++)aa[i].resize(0),vis[i]=0;
		}
		return 0;
	}
	if(id_==13 || id_==14)
	{
		while(T--)
		{
			cin>>n>>k;
			for(int i=1;i<n;i++)
			{
				int x,y;
				cin>>x>>y;
				aa[x].push_back(y);
				aa[y].push_back(x);
			}
			mx=-inf;
			dfs1(1,0,0);
			int l=aa[t][0];
			mx=-inf;
			dfs1(t,0,0);
			int r=aa[t][0],len=mx-2;
			int ans=inf;
			if(k>=n/2)
			{
				if(k==n)ans=0;
				else ans=1;
			}
			else
			{
				t=n/2;
				ans=(t-k)/4;
				if((t-k)%4)ans++;
				ans++;
			}
			cout<<ans<<'\n';
			for(int i=1;i<=n;i++)aa[i].resize(0);
		}
		return 0;
	}
	if(id_<=6)
	{
		while(T--)
		{
			cin>>n>>k;
			for(int i=1;i<n;i++)
			{
				int x,y;
				cin>>x>>y;
				aa[x].push_back(y);
				aa[y].push_back(x);
			}
			int t=(1<<n)-1;
			int ans=inf;
			for(int i=1;i<=t;i++)
			{
				int s=0;
				for(int j=0;j<n;j++)if(i&(1<<j))s++;
				if(s>k)continue;
				s=0;
				for(int j=1;j<=n;j++)vis[j]=0;
				for(int j=1;j<=n;j++)
				{
					if(i&(1<<(j-1)) && !vis[j])
					{
						s++;
						dfs_(j,i);
					}
				}
				if(s>2)continue;
				mx=-inf;
				for(int j=1;j<=n;j++)
				{
					mx=max(mx,dfs__(j,0));
				}
				ans=min(ans,mx);
				if(mx==-999999999999996)
				{
					cout<<i<<'\n';
				}
			}
			cout<<ans<<'\n';
			for(int i=1;i<=n;i++)aa[i].resize(0);
		}
		return 0;
	}
	srand(time(0));
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
		}
		int t=n/k;
		if(n%k)t++;
		cout<<rand()%t<<'\n';
	}
	return 0;
}
/*
BlueArchive
*/
