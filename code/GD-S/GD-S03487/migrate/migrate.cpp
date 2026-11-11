#include <bits/stdc++.h> 
using namespace std;
int c,t,n,d,b[500005],ans;
struct nd{
	int nxt,v;
}a[500050];
void build(int u,int v){
	a[++tot].nxt=h[u]
	h[u]=tot;
	a[tot].v=v;
}
int lca(int x){
	for(i=h[x];i;i=a[i].nxt){
		int y=a[i].v;
	}
	return y;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
			if(lca(b[i])==lca(b[i-1])) ans++;
		}
		printf("%d",ans);
	}
	
	
	
}
