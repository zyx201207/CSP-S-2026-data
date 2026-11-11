#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,qw=1,a[1500005];
long long op[1500005];
bool vis[1500005],v[1500005];
struct zw{
	int y,t,last;
}w[1500005];
void ww(int x,int y,int t){
	w[qw].y=y;
	w[qw].t=t;
	w[qw].last=a[x];
	a[x]=qw++;
}
void dij(int x){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
	memset(op,0x7f,sizeof(op));
	memset(vis,0,sizeof(vis));
	op[x]=0;
	q.push({0,x});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=a[u];i;i=w[i].last){
			int y=w[i].y;
			if(op[y]>op[u]+w[i].t){
				op[y]=op[u]+w[i].t;
				q.push({op[y],y});
			}
		}
	}
}
//void bfs(){
//	queue<int> q;
//	q.push(1);
//	v[1]=1;
//	while(!q.empty()){
//		int x=q.front();
//		cout<<x<<endl;
//		q.pop();
//		for(int i=a[x];i;i=w[i].last){
//			int y=w[i].y;
//			if(!v[y])q.push(y),v[y]=1;
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1,k;i<=m;i++){
		cin>>k;
		ww(i,i+m,k);
		ww(i+m,i,k);
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,aa,t;j<=k;j++){
			cin>>aa>>t;
			ww(aa+m,2*m+i,t); 
			ww(2*m+i,aa+m,t); 
		}
	}
	for(int r=1,xr,yr;r<=q;r++){
		cin>>xr>>yr;
		dij(xr);
		cout<<op[yr]<<endl;
	}
	return 0;
}
