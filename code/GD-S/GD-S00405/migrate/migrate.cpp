#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6;
int n,to[N+5];
ll d,a[N+5],ans,l[N+5],r[N+5],dis[N+5],cnt[N+5];
bool flag[N+5],flag2[N+5],vis[N+5];
vector<int>e[N+5];
void solve1()
{
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		dis[i]=0;cnt[i]=1;
		for(int j=i+1;j<=n;j++) dis[j]=1e9;
		for(int j=i;j<=n;j++)
		{
			//cout<<i<<" "<<j<<" "<<dis[j]<<" "<<cnt[j]<<'\n';
			if(cnt[j]==2) ans++;
			for(int k=j+1;k<=n;k++)
			{
				if(a[k]-a[j]>d) break;
				if(dis[k]>dis[j]+1) dis[k]=dis[j]+1,cnt[k]=cnt[j];
				else if(dis[k]==dis[j]+1) cnt[k]+=cnt[j];
			}
		}
	}
	cout<<ans<<'\n';
}
void solve()
{
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++) cin>>a[i],e[i].clear(),flag[i]=flag2[i]=0;
	for(int i=1;i<=n;i++)
	{
		int l=i+1,r=n,id=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[mid]-a[i]<=d) l=mid+1,id=mid;
			else r=mid-1;
		}
		to[i]=id;
		if(id!=i) e[id].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(to[i]!=i&&to[to[i]]!=to[i]&&to[to[i]]==to[to[i]-1]) flag[i]=1,flag2[i]=1;
	}
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(to[i]!=i&&to[i]-1>i&&to[to[i]]!=to[i])
		{
			ans+=(to[to[i]-1]-to[i]);
			if(to[to[i]-1]==to[to[i]]) ans--;
		}
		if(!vis[i]) l[i]=1;
		if(flag[i])
		{
			if(flag[to[i]]) l[to[i]]=1;
			else l[to[i]]=2;
		}
		else l[to[i]]=l[i]+1;
		vis[to[i]]=1;
		//cout<<i<<" "<<ans<<'\n';
	}
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=n;i>=1;i--)
	{
		if(!vis[i]) r[i]=1;
		if(flag2[i])
		{
			for(int son:e[i])
			{
				if(flag2[son]) r[son]=1;
				else r[son]=2;
				vis[son]=1;
			}
		}
		else for(int son:e[i]) r[son]=r[i]+1,vis[son]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]&&(to[i]-2==i||to[to[i]-2]!=to[to[i]])) ans=ans+l[i]*r[to[to[i]]];
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,_=1;cin>>c>>_;
	while(_--)
	{
		if(c<=10) solve1();
		else solve();
	}
	return 0;
}
