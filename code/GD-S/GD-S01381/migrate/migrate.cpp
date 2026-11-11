#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],v,ans,cnt;
int mi=1e9;
bool f=1;
void dfs(int u,int step){
	if(step>mi) return;
	if(u==v){
		mi=min(mi,step);
		return;
	}
	for(int i=u+1;i<=n;i++){
		if(x[i]-x[u]>d) break;
		dfs(i,step+1);
	}
}
void dfs1(int u,int step){
	if(!f) return;
	if(step>mi) return;
	if(u==v){
		if(step==mi) ans++;
		if(ans>2){
			f=0;
			return;
		}
		return;
	}
	for(int i=u+1;i<=n;i++){
		if(x[i]-x[u]>d) break;
		dfs1(i,step+1);
		if(!f) return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		cnt=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0;f=1;mi=1e9;
				v=j;
				dfs(i,0);
				dfs1(i,0);
				if(ans==2) cnt++;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
