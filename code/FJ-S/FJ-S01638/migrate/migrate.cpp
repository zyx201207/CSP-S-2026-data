#include<bits/stdc++.h>
using namespace std;
int c,t,d,n,ans;
const int maxn=2e6+9;
int cnt[maxn],x[maxn];
void dfs2(int k,int s)
{
	if(cnt[k]==s&&k>2&&cnt[k]>=2) ans++;
	for(int i=k+1;i<=n;i++)
	{
		if(x[i]-x[k]<=d)
		{
			s++;
			dfs2(i,s);
			s--;
		}
	}
}
void dfs(int k,int s)
{
	cnt[k]=min(cnt[k],s);
	for(int i=k+1;i<=n;i++)
	{
		if(x[i]-x[k]<=d) 
		{
			s++;
			dfs(i,s);
			s--;
		}
	}
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	cin>>x[i];
	for(int i=1;i<=n;i++)
	cnt[i]=INT_MAX;
	ans=0;
	dfs(1,0);
	dfs2(1,0);
	cout<<ans<<'\n';
}
int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

