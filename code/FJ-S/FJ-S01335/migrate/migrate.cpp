#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,d,ans,x[N];
int vis[N],f[N],cnt[2],a[2][N]; 
vector<int>mp[N];
void dfs(int s)
{
	int now=1,last=0;
	for(int i=1;i<=n;i++)vis[i]=f[i]=0;
	cnt[now]=0,cnt[last]=1;
	a[last][1]=s;vis[s]=1;
	for(int i=1;i<=n-i;i++)
	{
		for(int j=1;j<=cnt[last];j++)
		{
			for(int k=0;k<mp[a[last][j]].size();k++)
				f[mp[a[last][j]][k]]++;
		}
		for(int j=1;x[j]-x[s]<=d*i&&j<=n;j++)
		{
			if(f[j])a[now][++cnt[now]]=j;
			if(f[j]==2&&vis[j]==0)ans++;
			vis[j]=1;
			f[j]=0;
		}
		swap(now,last);
		cnt[now]=0;
	}
	
} 
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<n;i++)
		if(x[i+1]-x[i]>d){n=i;break;}
	for(int i=1;i<=n;i++)mp[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)mp[i].push_back(j);
				else break;
			}
	ans=0;
	for(int i=1;i<=n;i++)dfs(i);
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

