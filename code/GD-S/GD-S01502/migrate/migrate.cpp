#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c,t,n,d,x[5005],sum[5005],vis[5005][5005],minvis[5005][5005];
int path[5005],cnt;
void solve(int now){
	if(now==n+1) return;
	for(int i = now+1;i <= n;i++){
		if(x[i]-x[now]>d) break;
		path[++cnt]=i;
		for(int i = 1;i <= cnt;i++) sum[path[i]]++;
		for(int j = 1;j <= cnt;j++){
			if(sum[path[j]]==minvis[j][now]) vis[j][now]++;
			if(sum[path[j]]<minvis[j][now]){
				minvis[j][now]=sum[path[j]];
				vis[j][now]=1;
			}
		}
		solve(i);
		for(int i = 1;i <= cnt;i++) sum[path[i]]--;
		cnt--;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(sum,0,sizeof(sum));
		memset(vis,0,sizeof(vis));
		memset(minvis,0x3f,sizeof(minvis));
		for(int i = 1;i <= n;i++) cin>>x[i];
		path[++cnt]=1;
		solve(1);
		int ans=0;
//		for(int i = 1;i <= n;i++){
//			for(int j = i+1;j <= n;j++) cout<<minvis[i][j]<<' ';
//			cout<<'\n';
//		}
		for(int i = 1;i <= n;i++) for(int j = i+1;j <= n;j++) if(vis[i][j]==2) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
