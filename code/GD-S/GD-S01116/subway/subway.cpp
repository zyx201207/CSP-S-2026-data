#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,Q=1e5+5;
struct edge{
	int to,nx,v;
}e[4*N];
struct heap{
	struct node{
		int id;
		ll v;
	}h[N+500];
	int cnt;
	bool pd(int i,int j){
		return h[i].v<h[j].v;
	}
	void pop(){
		h[1]=h[cnt--];
		int i=1;
		while(i*2<=cnt){
			int j=i*2;
			if(j<cnt&&pd(j,j+1))j++;
			if(pd(j,i))swap(h[i],h[j]),i=j;
			else break;
		}
	}
	void push(node x){
		h[++cnt]=x;
		int i=cnt;
		while(i/2){
			if(pd(i,i/2))swap(h[i],h[i/2]),i/=2;
			else break;
		}
	}
}q;
int cnt,h[N];
int C,n,m,d,T;
int w[N];
struct nd{
	int x,y,id;
}qu[Q];
void add(int x,int y,int z){
	e[++cnt]=(edge){y,h[x],z};
	h[x]=cnt;
}
bool cmp(nd x,nd y){
	return x.x<y.x;
}
ll dis[N+500],ans[Q];
bool bz[N];
void dij(int SA){
	q.cnt=0;
	for(int i=1;i<=m+n;i++)dis[i]=1e18,bz[i]=0;
	dis[SA]=0;
	q.push({SA,0});
//	cout<<SA<<":\n";
	for(int i=1;i<m+n;i++){
		while(q.cnt&&bz[q.h[1].id]) q.pop();
		if(!q.cnt)break;
		int x=q.h[1].id;
	//	cout<<"x="<<x<<"\n";
		bz[x]=1;
		for(int p=h[x],y,z;p;p=e[p].nx){
			y=e[p].to,z=e[p].v;
			if(dis[y]>z+dis[x]){
				dis[y]=z+dis[x];
				q.push({y,dis[y]});
			}
		}
	}
//	for(int i=1;i<=m;i++)cout<<dis[i]<<" ";
//	cout<<"\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&T);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	int s=0;
	for(int i=1,x,y;i<=n;i++){
		int ki=0;
		scanf("%d",&ki);
		s+=ki;
		for(int j=1;j<=ki;j++){
			scanf("%d%d",&x,&y);
			add(m+i,x,y);
			add(x,m+i,y);
		} 
	}
	for(int i=1;i<=T;i++)scanf("%d%d",&qu[i].x,&qu[i].y),qu[i].id=i;
	sort(qu+1,qu+T+1,cmp);
//	cout<<1<<"\n";
	for(int i=1,j;i<=T;i=j){
		j=i+1;
		while(qu[i].x==qu[j].x)j++;
		int SA=qu[i].x;
		dij(SA);
		for(int k=i;k<j;k++){
			int y=qu[k].y;
			ans[qu[k].id]=dis[y]+1ll*w[SA]+1ll*w[y];
		//	printf("dis[%d]=",y);
		//	cout<<dis[y]<<"\n";
		} 
	}
	for(int i=1;i<=T;i++)printf("%lld\n",ans[i]);
	return 0;
} /*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
