#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[2000001];
int dis[5001][5001],cnt[5001][5001];
vector<int>e[2000001];
pair<int,int>gt(int x)
{
	int l=1,r=x,an=x;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[x]-a[mid]<=d) r=mid-1,an=mid;
		else l=mid+1;
	}
	l=x,r=n;
	int ann=x;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]-a[x]<=d) l=mid+1,ann=mid;
		else r=mid-1;
	}
	return {an,ann};
}
int cid;
//int f[2000001],g[2000001];
//int s1[2000005],s2[2000005];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i],e[i].clear();
	if(cid>=11&&cid<=14)
	{
		int ans=0;
//		for(int i=1;i<=n;i++) f[i]=g[i]=1;
//		s1[0]=s2[n+1]=0;
//		for(int i=1;i<=n;i++)
//		{
//			pair<int,int>A=gt(i),B=gt(i+1);
//			if(i==n) f[i]+=s1[i-1]-s1[A.first-1];
//			else f[i]+=s1[B.first-1]-s1[A.first-1];
//			s1[i]=s1[i-1]+f[i];
////			cout<<A.first<<" "<<B.first<<" "<<f[i]<<"!\n";
//		}
//		for(int i=n;i>=1;i--)
//		{
//			pair<int,int>A=gt(i),B=gt(i-1);
//			if(i==1) g[i]+=s2[i+1]-s2[A.second+1];
//			else g[i]+=s2[B.second+1]-s2[A.second+1];
//			s2[i]=s2[i+1]+g[i];
////			cout<<s2[i]<<"\n";
//		}
		for(int i=2;i<=n-2;i++)
		{
			pair<int,int>A=gt(i),B=gt(i+1),C=gt(i+2),D=gt(i-1);
			int la=max(A.first,B.first),ra=min(i-1,C.first-1),rb=min(A.second,B.second),lb=max(i+2,D.second+1);
			ans+=max(0ll,ra-la+1)*max(0ll,rb-lb+1);
//			cout<<i<<" "<<la<<" "<<ra<<" "<<lb<<" "<<rb<<"\n";
//			ans+=max(0ll,s1[ra]-s1[la-1])*max(0ll,s2[lb]-s2[rb+1]);
//			cout<<s2[lb]-s2[rb+1]<<"\n";
		}
		cout<<ans<<"\n";
		return;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=2e9,cnt[i][j]=0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[j]-a[i]<=d) e[i].push_back(j),e[j].push_back(i);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		queue<int>q;
		q.push(i),dis[i][i]=0,cnt[i][i]=1;
		while(q.size())
		{
			int x=q.front();q.pop();
			for(int y:e[x])
			{
				if(dis[i][y]>dis[i][x]+1) dis[i][y]=dis[i][x]+1,cnt[i][y]=cnt[i][x],q.push(y);
				else if(dis[i][y]==dis[i][x]+1) cnt[i][y]+=cnt[i][x],cnt[i][y]=min(cnt[i][y],3ll);
			}
		}
		for(int j=i;j<=n;j++) if(cnt[i][j]==2) ans++;
	}
	cout<<ans<<"\n";
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>cid>>t;
	while(t--) solve();
	return 0;
}
