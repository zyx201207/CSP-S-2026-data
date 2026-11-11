#include <bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar_unlocked

inline int read(){
	int x=0,v=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')v=-1;
		ch=gc();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+(ch-'0');
		ch=gc();
	}
	return x*v;
}

const int M=5*1e5+10,N=505,D=20;//
int c,n,m,d,q;
int w[M],have[M],a[N],t[N];

int ver[M*4],edge[M*4],nxt[M*4],head[M*(D+1)],tot=1;
void add(int x,int y,int z){
	ver[++tot]=y,edge[tot]=z;
	nxt[tot]=head[x],head[x]=tot;
}

bool v[M*(D+1)];
int ans[M*(D+1)];
void dijkstra(int st){
	memset(v,0,sizeof(v));
	memset(ans,0x3f,sizeof(ans));
	priority_queue <pair<int,int> > q;
	q.push(make_pair(0,st));
	ans[st]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i],z=edge[i];
			if(v[y])continue;
			if(ans[y]>ans[x]+z){
				ans[y]=ans[x]+z;
				q.push(make_pair(-ans[y],y));
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			a[j]=read(),t[j]=read();
			int ha=++have[a[j]];
			add(a[j],a[j]+m*ha,t[j]);
			add(a[j]+m*ha,a[j],t[j]);
		}
		for(int j=1;j<=k;j++){
			if(j>1){
				add(a[j]+m*have[a[j]],a[j-1]+m*have[a[j-1]],0);
			}
			if(j<k){
				add(a[j]+m*have[a[j]],a[j+1]+m*have[a[j+1]],0);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		dijkstra(x);
		cout<<w[x]+ans[y]+w[y]<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

