#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,l,a[200005],d[200005],vis[200005],cnt[200005];
void bfs(int x)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,x}),d[x]=0,cnt[x]=1;
	int xx=x;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		int ll=lower_bound(a+1,a+n+1,a[x]-l)-a,r=upper_bound(a+1,a+n+1,a[x]+l)-a-1;
		if(a[x-1]<a[x]-l) ll=x;
		if(a[n]<=a[x]+l) r=n; 
		for(int i=ll; i<=r; i++)
		{
			if(d[i]>d[x]+1) d[i]=d[x]+1,cnt[i]=cnt[x],q.push({d[i],i});
			else if(d[i]==d[x]+1) cnt[i]+=cnt[x];
		}
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int sum=0;
		cin>>n>>l;
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=1; i<=n; i++)
		{
			memset(cnt,0,sizeof(cnt[0])*(n+2));
			memset(vis,0,sizeof(vis[0])*(n+2));
			memset(d,0x3f,sizeof(d[0])*(n+2));
			bfs(i);
			for(int j=i+1; j<=n; j++) sum+=(cnt[j]==2);
		}
		cout<<sum<<'\n';
	}
	return 0;
}

