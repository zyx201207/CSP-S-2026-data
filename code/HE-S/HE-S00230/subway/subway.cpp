#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int c,n,m,d,q,a[N],b[510][2],pre[N],cnt,dis[N];
struct E{
	int from,to,nx,val;
}e[N*2];
void ae(int u,int v,int val){
	e[++cnt].from=u;
	e[cnt].to=v;
	e[cnt].nx=pre[u];
	e[cnt].val=val;
	pre[u]=cnt;
}
struct Node{
	int x,d;
	bool friend operator < (Node a,Node b){
		return a.d>b.d;
	}
}np,xp;
void djstl(int x){
	memset(dis,0x3f,sizeof(dis));
	np.x=x;
	np.d=0;
	dis[x]=0;
	priority_queue<Node> pq;
	pq.push(np);
	while(!pq.empty()){
		np=pq.top();
		pq.pop();
		int x=np.x;
		for(int i=pre[x];i;i=e[i].nx){
			int to=e[i].to;
			if(dis[to]>dis[x]+e[i].val){
				dis[to]=dis[x]+e[i].val;
				xp.x=to;
				xp.d=dis[to];
				pq.push(xp);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>b[j][0]>>b[j][1];
		}
		for(int j=1;j<x;j++){
			ae(b[j][0],b[j+1][0],b[j][1]+b[j+1][1]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		djstl(x);
		cout<<dis[y]+a[x]+a[y]<<endl;
	}
	return 0;
}


