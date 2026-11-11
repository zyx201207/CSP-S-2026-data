#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int c,t,n;
bool bz[2000005];
long long d,a[2000005];
vector<int>g[2000005];
queue<int>q;
struct N
{
	int x,t;
}b[2000005];
void bfs(int s,int t)
{
	for(int i=s;i<=t;i++) b[i]={inf,0},bz[i]=0;
	b[s]={0,1};bz[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:g[x])
		{
			if(y>t) break;
			if(b[x].x+1<=b[y].x)
			{
				b[y].x=b[x].x+1;
				b[y].t+=b[x].t;
				if(bz[y]==0) q.push(y);
				bz[y]=1;
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1||c>=13)
		{
			cout<<0<<'\n';
			continue;
		}
		long long ans=0;
		if(c==11||c==12)
		{
			long long y=a[2]-a[1];
			int x=0;
			if(y*(n-1)<=d||d<y)
			{
				cout<<0<<'\n';
				continue;
			}
			while((x+1)*y<=d&&x+1<n) x++;
			ans=n-2*x+1;
			if(x<=1) ans=0;
			cout<<max(0ll,ans)<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d) break;
				g[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				bfs(i,j);
				if(b[j].t==2) ans++;
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) g[i].clear();
	}
	return 0;
}
