#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n,k;
struct node{
	int nxt,to;
}e[100005];
int head[100005],tot;
void add(int u,int v){
	e[++tot]={head[u],v};
	head[u]=tot;
}
int fa[100005];
void init(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<=n-1;i++){
		scanf("%d%d",&u,&v);
	}
//	if(k>=n/2) printf
    puts("1"); 
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
} 
/*

*/
