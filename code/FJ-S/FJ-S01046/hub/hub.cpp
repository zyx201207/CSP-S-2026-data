#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int id,n,m,f[N],d[N];
vector<int>v[N];
int fa(int x)
{
	if(x==f[x]) return x;
	return f[x]=fa(f[x]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if(n<=10)
	{
		int ans=1e9;
		for(int s=0;s<(1<<n);s++)
		{
			int cnt=__builtin_popcount(s);
			if(cnt>m) continue;
			for(int i=1;i<=n;i++) f[i]=i;
			for(int i=1;i<=n;i++)
			{
				for(int j:v[i])
				{
					if(((s>>i-1)&1)&&((s>>j-1)&1))
					{
						if(fa(i)!=fa(j)) f[fa(i)]=fa(j),cnt--;
					}
				}
			}
			if(cnt>2) continue;
			queue<int>q;
			for(int i=1;i<=n;i++) d[i]=1e9;
			for(int i=1;i<=n;i++)
			{
				if((s>>i-1)&1) d[i]=0,q.push(i);
			}
			while(!q.empty())
			{
				int x=q.front();
				q.pop();
				for(int y:v[x]) if(d[y]==1e9) d[y]=d[x]+1,q.push(y);
			}
			int maxx=0;
			for(int i=1;i<=n;i++) maxx=max(maxx,d[i]);
			ans=min(ans,maxx);
		}
		cout<<ans<<"\n";
	}
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>id>>t;
	while(t--) solve();
	return 0;
}

