#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
const int N=2e6+20,inf=1e18;
vector<int> p[N];
int tid,n,d,a[N];
queue<int> q;
bool vis[N];
void bfs(int st,int *dis,int *cnt)
{
	fo(i,1,n)dis[i]=-1,cnt[i]=0,vis[i]=0;
	dis[st]=0;cnt[st]=1;q.push(st);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i:p[x])
			if(dis[i]==-1)
			{
				dis[i]=dis[x]+1;
				q.push(i);
			}
	}
	q.push(st);
	cnt[st]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i:p[x])
			if(dis[i]==dis[x]+1)
			{
				cnt[i]+=cnt[x];
				if(!vis[i])q.push(i),vis[i]=1;
			}
	}
}
int dis[5020],cnt[5020][5020];
void solve()
{
	cin>>n>>d;
	fo(i,1,n)cin>>a[i],p[i].clear();
	if(tid<=10)
	{
		fo(i,1,n)
			fo(j,i+1,n)
				if(a[j]-a[i]<=d)
				{
					p[i].push_back(j);
					p[j].push_back(i);
				}
				else break;
		fo(i,1,n)bfs(i,dis,cnt[i]);
//		fo(i,1,n)
//		{
//			cout<<"i="<<i<<":   ";
//			for(auto j:p[i])cout<<j<<",";
//			cout<<endl;
//		}
//		fo(i,1,n)
//		{
//			fo(j,1,n)cout<<"i="<<i<<",j="<<j<<":   "<<cnt[i][j]<<endl;
//		}
		int ans=0;
		fo(u,1,n)
			fo(v,u+1,n)
				if(cnt[u][v]==2)
					ans++;
		cout<<ans<<endl;
	}
	if(tid==11||tid==12)
	{
		int c=d/(a[2]-a[1]);
		if(c==0||c==1)cout<<0<<endl;
		else cout<<max(0ll,n-2*c+1)<<endl;
	}
	if(tid==13||tid==14)
	{
		
	}
	if(15<=tid&&tid<=18)
	{
		
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>tid>>T;
	while(T--)solve();
	return 0;
}
