#include <bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
//head
const int N=2e6+5;
ll a[N];
int r[N],cnt[N],dis[N];
void dfs(int u,int step)
{
	cnt[u]++,dis[u]=step;
	int v=r[u];
	while(u<v){
		if((!cnt[v]||dis[v]==step+1)&&cnt[v]<=2) dfs(v,step+1);
		v--;	
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int c,T;cin>>c>>T;
	while(T--)
	{
		int n;ll d;cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			r[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cnt[j]=0,dis[j]=0;
			dfs(i,0);
			for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
		}
		cout<<ans<<'\n';
	}
}
