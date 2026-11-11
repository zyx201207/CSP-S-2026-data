#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int M=5e4+5,N=505;
int c,n,m,d,q,w[M],t1[M],t2[M];
struct node{
	int to,nex,len;
}a[M*2];
int pre[M],k;
void add(int ui,int vi,int len){
	a[++k].to=vi;
	a[k].nex=pre[ui];
	a[k].len=len;
	pre[ui]=k;
}int s,t;
int dis[M];
bool vis[M];
void dijkstra(){
	for(int i=1;i<=m;i++)	vis[i]=0;
	memset(dis,0x3f,sizeof(dis));
	priority_queue<PII,vector<PII>,greater<PII> >q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int h=q.top().second;
		q.pop();
		if(vis[h])continue;
		vis[h]=1;
		for(int i=pre[h];i;i=a[i].nex){
			int to=a[i].to;
			if(!vis[to]&&dis[to]>dis[h]+a[i].len){
				dis[to]=dis[h]+a[i].len;
				q.push({dis[to],to});
			}
		}
	}
}
bool fs[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}for(int i=1;i<=n;i++){
		int ki,lastx;
		scanf("%d",&ki);
		int xi,wi;
		for(int j=1;j<=ki;j++){
			scanf("%d%d",&xi,&wi);
			t1[j]=xi;
			t2[j]=wi;	
		}
		for(int l=1;l<=ki;l++){
			for(int p=l+1;p<=ki;p++){
				add(t1[l],t1[p],t2[l]+t2[p]);
				add(t1[p],t1[l],t2[p]+t2[l]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&s,&t);
		dijkstra();
		printf("%d\n",dis[t]+w[s]+w[t]);
	}
	return 0;
}
