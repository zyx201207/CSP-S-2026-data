#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked 
using namespace std;
const int maxm=5e4+3;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
void write(int a){
	if(a<0)putchar('-'),a=-a;
	if(a>9)write(a/10);
	putchar(a%10+'0');
	return;
}

int c,n,m,d,q;
int w[maxm],a[503][maxm],t[503][maxm],k[503];
int vis[503][maxm];
int vl[503];
struct node{
	int op,tim,pos;//op=1为线路 op=2为站台 
};
int bfs(int u,int v){
	int res=w[u];
	queue<node>q;
	q.push({2,0,u});
	int gc=1e9;
	memset(vl,1e9+3,sizeof(vl));
	while(!q.empty()){
		node p=q.front();//当前位置类型、时间和位置 
		q.pop();
		if(p.op==2&&p.pos==v)gc=min(gc,p.tim);
		if(p.op==2){
			for(int i=1;i<=n;++i){
				if(vis[i][p.pos]!=0&&vl[i]>p.tim+t[i][vis[i][p.pos]])q.push({1,p.tim+t[i][vis[i][p.pos]],i}),vl[i]=p.tim;
			}
		}
		if(p.op==1){
			for(int i=1;i<=k[p.pos];++i){
				q.push({2,p.tim+t[p.pos][i],a[p.pos][i]});
			}
		}
	}
	res+=gc;
	res+=w[v];
	return res;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;++i)w[i]=read();
	for(int i=1;i<=n;++i){
		k[i]=read();
		for(int j=1;j<=k[i];++j){
			a[i][j]=read();//第j个站台的编号 
			vis[i][a[i][j]]=j;//第i条线路含有该站台 并记录这个站台是第j个站台 
			t[i][j]=read();//该站台到第i条线路的时间 
		}
	}
	for(int i=1,x,y;i<=q;++i){
		x=read();y=read();
		cout<<bfs(x,y)<<'\n';
	}
	
	return 0;
}

