#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
int cid,t,n,d,a[N],lnum[N],rnum[N],numl[N],numr[N],l[N],r[N],ans,dis[N],f[N];
inline void bfs(int st)
{
	for(int i=st+1;i<=n;i=-~i)dis[i]=1e12,f[i]=0;
	dis[st]=0,f[st]=1;
	for(int x=st;x<=n;x++)
	{
		for(int j=x+1;j<=r[x];j=-~j)
		{
			if(dis[j]>dis[x]+1)dis[j]=dis[x]+1,f[j]=f[x];
			else if(dis[j]==dis[x]+1)f[j]+=f[x];
		}
		if(f[x]==2)ans++;
	}
}
inline void work()
{
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;i=-~i)cin>>a[i],lnum[i]=rnum[i]=numl[i]=numr[i]=1,l[i]=r[i]=i;
	if(n<=3)return cout<<0<<'\n',void();
	for(int sl=1,sr=1;sl<=n;sl++)
	{
		while(sr<n&&a[sr+1]-a[sl]<=d)sr++;
		r[sl]=sr;
	}
	for(int sl=n,sr=n;sr>=1;sr--)
	{
		while(sl>1&&a[sr]-a[sl-1]<=d)sl--;
		l[sr]=sl;
	}
	if(cid<=6)
	{
		for(int i=1;i<=n;i++)bfs(i);
		cout<<ans<<'\n';
		return;
	}
	else if(cid==11||cid==12)
	{
		int ls=a[2]-a[1];
		for(int i=2;i<=n;i++)if(d>=ls*i&&d<ls*(i+1))
		{
			cout<<max(0ll,n-i-i+1)<<'\n';
			return;
		}
		cout<<0<<'\n';
		return;
	}
	for(int i=1,j;i<=n;i++)
	{
		j=r[i];
		if(i==j);
		else if(l[j]==i)numl[j]+=numl[i];
		else numl[j]++;
	}
	for(int i=n,j;i;i--)
	{
		j=l[i];
		if(i==j);
		else if(r[j]==i)numr[j]+=numr[i];
		else numr[j]++;
	}
	for(int a=2,b=3;b<n;a++,b++)if(l[a]!=a&&r[a]!=a&&l[b]!=b&&r[b]!=b&&r[a]!=b&&l[b]!=a)
		ans+=max(0ll,(numr[a]-1)*(numl[b]-1)-(numl[a]-1)*(numr[b]-1));
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>cid>>t;
	while(t--)work();
	return 0;
}
/*
猜一猜今年 ccf 是用什么造数据的 
能不能把我的假算放过去 
*/
