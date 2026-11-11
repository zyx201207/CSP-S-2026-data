#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
typedef pair<ll,int> pi;
ll dis[N];
bool f[N];
priority_queue<pi,vector<pi>,greater<pi>>q;
struct st{
	int to;ll len;int next;
	
}a[N];
int m;
struct node{
	int x,len;
}c[N];
int n,d,C,pre[N],Q,k;
void add(int u,int v,int len){
	a[++k]={v,len,pre[u]};
	pre[u]=k;
}
void bfs(int b,int e){
	while(!q.empty()){
		q.pop();
	}
	memset(dis,0x3f,sizeof(dis));
	memset(f,false,sizeof(f));
	q.push({0,b});
	f[b]=true;
	dis[b]=0;
	while(!q.empty()){
		pi h=q.top(); 
		q.pop();
		int l=h.first;
		int p=h.second;
		f[p]=true;
		if(p==e)return;
		for(int i=pre[p];i;i=a[i].next){
			int t=a[i].to;
			int nd=l+a[t].len;
			if(nd<dis[t]){
				dis[t]=nd;
				q.push({nd,t});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int ma=0;
	
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		int len;
		scanf("%d",&len);
		add(i,i+m,len);
		add(i+m,i,len);
		ma=max(ma,i+m);
	}
	int nod=ma;
	for(int i=1;i<=n;i++){
		int er;
		scanf("%d",&er);
		nod++;
		for(int i=1;i<=er;i++){
			int x,l;
			scanf("%d%d",&x,&l);
			add(nod,x+m,l);
			add(x+m,nod,l);
		}
	}
	while(Q--){
		int y;
		int x;
		scanf("%d%d",&x,&y);
		bfs(x,y);
		printf("%lld\n",dis[y]);
	}
	return 0;
}
