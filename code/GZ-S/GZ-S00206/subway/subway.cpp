//GZ-S00206 遵义市第四中学 杨嵩涵 
#include<bits/stdc++.h>
using namespace std;
const int N=500005,INF=2147483647;
template <typename T>inline void read(T &x){
	T f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	x=0;
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
int c,n,m,d,p,w[N],a[505][N],t[505][N],len,head[N];
struct Edge{
	int to,next,wt;
}e[N<<1];
struct node{
	int dx,mn;
};
void add(int u,int v,int wt){
	e[++len].to=v;
	e[len].wt=wt;
	e[len].next=head[u];
	head[u]=len;
}
long long dj(int x,int y){
	queue<node> qp;
	int vis[N],s=m,f[N];
	memset(vis,0,sizeof(vis));
	memset(f,INF,sizeof(f));
	qp.push({x,INF});
	vis[x]=1;
	f[x]=0;
	while(!qp.empty()){
		
		
		for(int i=head[x];i;i=e[i].next){
			if(vis[i])continue;
			if(f[i]>e[i].wt){
				f[i]=e[i].wt;
				vis[i]=1;
			}
		}
		
	}
	return f[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(p);
	for(int i=1;i<=m;++i){
		read(w[i]);
	}
	for(int i=1;i<=n;++i){
		int k;
		read(k);
		for(int j=1;j<=k;++j){
			read(a[i][j]);
			read(t[i][j]);
			if(j>1){
				add(a[i][j-1],a[i][j],t[i][j-1]+t[i][j]);
				add(a[i][j],a[i][j-1],t[i][j-1]+t[i][j]);
			}
			
		}
	} 
	while(p--){
		int x,y;
		long long ans=0;
		read(x);read(y);
		ans+=w[x]+w[y];
		ans+=dj(x,y);
		printf("%lld\n",ans);
	}
	return 0;
}

