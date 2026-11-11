#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=510,MAXM=5e6+1000,MAX=1e18;
ll heap_dex[MAXM],heap_num[MAXM],tot,top,c,n,m,d,q,oo[MAXN],k,dis[MAXM],Next[MAXM],head[MAXM],Cos[MAXM],ver[MAXM];
void heap_push(int index,int num){
	heap_dex[++tot]=index;heap_num[tot]=num;
	int i=tot,pa;
	pa=i>>1;
	while(pa>0 && heap_num[i]<heap_num[pa]){
		int x=heap_num[i],y=heap_dex[i];
		heap_num[i]=heap_num[pa];heap_dex[i]=heap_dex[pa];
		heap_num[pa]=x;heap_dex[pa]=y;
		i=i>>1;
		pa=i>>1;
	}
	return;
}
void heap_pop(){
	heap_num[1]=heap_num[tot];heap_dex[1]=heap_dex[tot];
	tot--;
	int i=1,son;
	son=i<<1;
	while(son<tot && min(heap_num[son],heap_num[son+1])<heap_num[i]){
		if(heap_num[son]>heap_num[son+1])son++;
		int x=heap_num[i],y=heap_dex[i];
		heap_num[i]=heap_num[son];heap_dex[i]=heap_dex[son];
		heap_num[son]=x;heap_dex[son]=y;
		i=i<<1;
		son=i<<1;
	}
	if(son==tot && heap_num[son]<heap_num[i]){
		int x=heap_num[i],y=heap_dex[i];
		heap_num[i]=heap_num[son];heap_dex[i]=heap_dex[son];
		heap_num[son]=x;heap_dex[son]=y;
	}
	return;
}
void Add_Edge(int u,int v,int cost){
	Next[++top]=head[u];
	ver[top]=v;
	Cos[top]=cost;
	head[u]=top;
	return;
}
ll Find(int start,int end){
	for(int i=1;i<=n+m;i++)dis[i]=MAX;
	int u,t=0;
	dis[start]=0;tot=0;
	heap_push(start,dis[start]);
	while(t<n+m){
		u=heap_dex[1];heap_pop();t++;
//		cout<<dis[u]<<" "<<
		int p=head[u];
		while(p){
			int v=ver[p];
			if(dis[u]+Cos[p]<dis[v]){
				dis[v]=dis[u]+Cos[p];
				heap_push(v,dis[v]);
			}
			p=Next[p];
		}
	}
	return dis[end];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>oo[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,t;
			cin>>u>>t;
			Add_Edge(u,i+m,t);
			Add_Edge(i+m,u,t);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<Find(x,y)+oo[x]+oo[y]<<"\n";
	}
	return 0;
}
