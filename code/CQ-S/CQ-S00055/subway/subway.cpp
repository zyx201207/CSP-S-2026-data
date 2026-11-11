#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,r,a[1005],dis[1005],e[1005][1005];
bool vis[1005];
struct qwq{
	int x,dis;
	bool operator<(const qwq &b)const{
		return dis>b.dis;
	}
};
priority_queue<qwq>qp;
vector<int>q,p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&r);
	for(int i=1;i<=m;i++)scanf("%d",a+i);
	memset(e,0x3f,sizeof(e));
	for(int i=1,z;i<=n;i++){
		scanf("%d",&z);
		for(int j=1,x,y;j<=z;j++){
			scanf("%d%d",&x,&y);
			q.push_back(x);
			p.push_back(y);
		}
		for(int j=0;j<z-1;j++)
			for(int w=j+1;w<z;w++){
				e[q[j]][q[w]]=min(e[q[j]][q[w]],p[j]+p[w]);
				e[q[w]][q[j]]=min(e[q[w]][q[j]],p[j]+p[w]);
			}
		q.clear();
		p.clear();
	}
	while(r--){
		int x,y;
		scanf("%d%d",&x,&y);
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=m;i++)vis[i]=0;
		qp.push((qwq){x,0});
		dis[x]=0;
		while(!qp.empty()){
			qwq x=qp.top();
			qp.pop();
			if(!vis[x.x])
				for(int i=1;i<=m;i++)
					if(dis[i]>x.dis+e[x.x][i]){
						dis[i]=x.dis+e[x.x][i];
						qp.push((qwq){i,dis[i]});
					}
			vis[x.x]=1;
		}
		printf("%d\n",dis[y]+a[x]+a[y]);
	}
	return 0;
}
