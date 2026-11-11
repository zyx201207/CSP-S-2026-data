#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,d,a[2000005],ans,dis[2000005],cnt[2000005];
void dfs(int x,int st){
	if(!dis[x]||dis[x]>st) dis[x]=st,cnt[x]=0;
	if(st>dis[x]) return;
	cnt[x]++;
	for(int i=upper_bound(a+1,a+n+1,a[x]+d)-a-1;i>x;i--) dfs(i,st+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>d>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		for(int i=1;i<n;i++){
			memset(dis,0,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			dfs(i,0);
			for(int j=1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

