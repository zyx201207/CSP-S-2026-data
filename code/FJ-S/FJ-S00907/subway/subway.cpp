#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	char c;
	int x=0,f=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int MAXN=1e6+5;
int test,n,m,d,q;
int w[MAXN],siz[MAXN];
int mymap[505][505];
int st_dis[505][505],dis[505];
vector<int> a[MAXN],t[MAXN];
struct node{
	int val,idx;
	bool operator<(const node &x)const{
		return val<x.val;
	}
}newx,nowx;
priority_queue<node> p;
void dijstra(int k){
	newx.idx=k;
	newx.val=0;
	p.push(newx);
	for(int i=1;i<=n;i++){
		dis[i]=2e16+5;
	}
	dis[k]=0;
	while(!p.empty()){
		newx=p.top();
		p.pop();
		int x=newx.idx;
		for(int i=1;i<=n;i++){
			if(i==x) continue;
			if(newx.val+mymap[x][i]<dis[i]){
				dis[i]=mymap[x][i]+newx.val;
				nowx.idx=i;
				nowx.val=dis[i];
				p.push(nowx);
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	test=read();
	n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int ki,xx,tt;
		ki=read();
		for(int j=1;j<=ki;j++){
			xx=read();tt=read();
			a[xx].push_back(i);
			t[xx].push_back(tt);
			siz[xx]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mymap[i][j]=2e16+5;
		}
		mymap[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<siz[i];j++){
			for(int k=j+1;k<siz[i];k++){
				int u=a[i][j],v=a[i][k];
				mymap[u][v]=min(mymap[u][v],t[i][j]+t[i][k]);
				mymap[v][u]=min(mymap[v][u],t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijstra(i);
		for(int j=1;j<=n;j++){
			st_dis[i][j]=dis[j];
		}
	}
	while(q--){
		int x,y;
		x=read();y=read();
		int ans=2e16+5;
		for(int i=0;i<siz[x];i++){
			for(int j=0;j<siz[y];j++){
				int u=a[x][i];
				int v=a[y][j];
				ans=min(ans,t[x][i]+st_dis[u][v]+t[y][j]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
