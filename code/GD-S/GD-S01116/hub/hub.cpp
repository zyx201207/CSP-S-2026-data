#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
struct edge{
	int to,nx;
}e[2*N];
int cnt,h[N];
int C,T,n,m;
int dis[1005][1005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};
	h[x]=cnt;
}
int q[N];
bool bz[N];
void bfs(int S){
	int ql=1,qr=1;
	q[1]=S;
	while(ql<=qr){
		int x=q[ql++];
		bz[x]=1;
		for(int p=h[x];p;p=e[p].nx){
			int y=e[p].to;
			if(!bz[y]){
				dis[S][y]=dis[S][x]+1;
				q[++qr]=y;
			}
		}
	}
}
int b[N];
int ans=1e9;
void dg(int x,int y){
	if(x>n&&y<=m)return;
	else if(y<=m){
		for(int i=x;i<=n;i++){
			b[y]=i;
			dg(i+1,y+1);
		}	
		return;
	}
	int mx=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1,x,y;i<=n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=1;j<=n;j++)bz[j]=0;
	}
	dg(1,1);
	return 0;
} /*

*/
