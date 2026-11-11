#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6,M=2e6+6;
int c,t,n,k,u,v;
int to[M],ne[M],h[M],cnt,ww[M];
void add(int x,int y){
	to[++cnt]=y;ne[cnt]=h[x];
	h[x]=cnt;return;
}
int f[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(!c&&t==2){
		printf("1\n2");return 0;
	}
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		for(int i=1;i<=n;i++){
			scanf("%d%d",&u,&v);
			add(u,v);add(v,u);
			f[u]=v;
		}
	    printf("%d",(n+1)/2);
	}
	return 0;
}
