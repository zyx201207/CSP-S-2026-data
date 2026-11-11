#include<bits/stdc++.h>
#define int long long
using namespace std;
int cw,t,n,d,x[5010],dl[5010][5010],sum,ans,vis[5010];
void dfs(int st,int ed,int mq,int lj){
	if(sum == 3 || lj > dl[st][ed]){
		return;
	}
	if(mq == ed){
		sum++;
	}
	for(int i = 1;i <= n;i++){
		if(i != mq && !vis[i] && abs(x[i] - x[mq]) <= d){
			vis[i] = 1;
			dfs(st,ed,i,lj + 1);
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&cw,&t);
	while(t--){
		ans = 0;
		scanf("%lld%lld",&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&x[i]);
		}
		memset(dl,0x3f,sizeof(dl));
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i == j) dl[i][j] = 0;
				if(abs(x[i] - x[j]) <= d){
					dl[i][j] = 1;
					dl[j][i] = 1;
				}
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				for(int k = 1;k <= n;k++){
					if(i == j) dl[i][j] = 0;
					else{
						dl[i][j] = min(dl[i][j],dl[i][k] + dl[k][j]);
					}
				}
			}
		}
		/*
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(dl[i][j] == 0x3f3f3f3f3f3f3f3f){
					cout<<-1<<' ';
				}else{
					cout<<dl[i][j]<<' ';
				}
			}
			puts("");
		}
		*/
		for(int i = 1;i <= n - 2;i++){
			for(int j = i + 2;j <= n;j++){
				if(dl[i][j] != 0x3f3f3f3f3f3f3f3f && dl[i][j] != 0 && dl[i][j] != 1){
					sum = 0;
					memset(vis,0,sizeof(vis));
					dfs(i,j,i,0);
					if(sum == 2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
