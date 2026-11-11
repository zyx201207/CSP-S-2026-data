#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,cnt=0;
long long w[500005];
int hd[500505];
int nxt[1000006];
int to[1000006];
int wv[1000006];
bool vis[500505];
int dis[500505];
struct C{
	int wh;
	int th;
	bool operator< (const C &b) const{
		return this->th >b.th;
	}
};
priority_queue<C>Q;
int dj(int x,int y){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	Q.push((C){x,0});
	while(!Q.empty()){
		int D=Q.top().wh;
		if(vis[D]==0){
			vis[D]=1;
			dis[D]=min(dis[D],Q.top().th);
			int p=hd[D];
			Q.pop();
			while(p!=0){
			Q.push((C){to[p],dis[D]+wv[p]});
			p=nxt[p];
			
			}
		}
		else{
			Q.pop();
		}
	}
	return dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k,a,t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&a);
			scanf("%d",&t);
			cnt++;
			nxt[cnt]=hd[i+m];
			hd[i+m]=cnt;
			to[cnt]=a;
			wv[cnt]=t;
			cnt++;
			nxt[cnt]=hd[a];
			hd[a]=cnt;
			to[cnt]=i+m;
			wv[cnt]=t;
		}
	}
	int X,Y;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&X,&Y);
		cout<<dj(X,Y)+w[X]+w[Y]<<"\n";
	}
	return 0;
}
