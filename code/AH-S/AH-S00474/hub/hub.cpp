#include<bits/stdc++.h>
using namespace std;
int n,k,t,aa,bb,ans;
int f[1005][1005];
bool f2[1005];
bool f3[15];
int vis[1005][1005];
bool ok[1005];
void dij(int gyyy,int qqq){
	int op=n;
	memset(ok,0,sizeof ok);
	vis[qqq][gyyy]=0;
	while(op--){
		int r=0x3f3f3f3f+1,t;
		for(int i=1;i<=n;i++){
			if(vis[qqq][i]<r&&!ok[i]){
				r=vis[qqq][i];
				t=i;
			}
		}
		ok[t]=1;
		for(int i=1;i<=n;i++){
			if(f[t][i]!=-1&&!ok[i]){
				vis[qqq][i]=min(vis[qqq][i],vis[qqq][t]+f[t][i]);
			}
		}
	}
}
void dfs2(int t){
	f3[t]=0;
	for(int i=1;i<=n;i++)
		if(f[t][i]!=-1&&f3[i]) dfs2(i);
}
void solve(){
	int summ=0;
	memset(f3,0,sizeof f3);
	for(int i=1;i<=n;i++) f3[i]=f2[i];
	for(int i=1;i<=n;i++){
		if(f3[i]){
			dfs2(i);
			summ++;
		}
	}
	if(summ>2) return;
	summ=0;
	for(int i=1;i<=n;i++){
		int summm=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			if(!f2[j]) continue;
			summm=min(summm,vis[i][j]);
		}
		summ=max(summ,summm);
	}
	ans=min(ans,summ);
}
void dfs1(int g,int sum){
	if(sum>=k){
		solve();
		return;
	}
	for(int i=g;i<=n;i++){
		if(!f2[i]){
			f2[i]=1;
			dfs1(i+1,sum+1);
			f2[i]=0;
		}
		
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>t;
	while(t--){
		ans=0x3f3f3f3f;
		cin>>n>>k;
		memset(f,-1,sizeof f);
		for(int i=1;i<n;i++){
			cin>>aa>>bb;
			f[aa][bb]=f[bb][aa]=1;
		}
		memset(vis,0x3f3f3f3f,sizeof vis);
		for(int i=1;i<=n;i++)
			dij(i,i);
		dfs1(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
