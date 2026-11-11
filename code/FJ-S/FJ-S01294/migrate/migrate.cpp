#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[1000001],flag=0,sum=0,now;
int head[1000001],cnt=0;
struct node{
	int to,nxt;
}edge[1000001];
void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int x,int y,int step){
	if(x>y) return;
	if(x==y){
		if(step<now){
			now=step;
			sum=1;
		}
		else if(step==now) sum++;
		return;
	}
	for(int i=head[x];i;i=edge[i].nxt){
		int v=edge[i].to;
		dfs(v,y,step+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%lld%lld",&c,&T);
	while(T--){
		int n,m,ans=0;
		memset(head,0,sizeof(head));
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>m) break;
				add(i,j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum=0;
				now=1e18;
				dfs(i,j,0);
				if(sum==2) ans++;
			}
		}
		printf("%lld\n",ans);
	} 
}
