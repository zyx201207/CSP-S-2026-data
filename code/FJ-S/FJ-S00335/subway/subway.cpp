//T2
#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}

void out(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)out(x/10);
	putchar(x%10+'0');
}
void write(int x){out(x);putchar(10);}
void wrote(int x){out(x);putchar(32);}

const int N=5e2+10;
const int M=1e3+10;
const int inf=1e18;

int C,n,m,d,q;
int det,ans;
int w[N],a[N][M],t[N][M];
int nxt[N][M],pre[N][M];

bool mp[N][M];
bool vis[M];

void dfs(int x,int lx,int cnt){
	if(cnt>ans)return ;
	if(x==det){
		ans=min(ans,cnt+t[lx][x]);
		return ;
	}
	if(lx!=0&&pre[lx][x]!=0&&!vis[pre[lx][x]]){			//原路返回  
		vis[pre[lx][x]]=1;
		dfs(pre[lx][x],lx,cnt);
		vis[pre[lx][x]]=0;
	}
	if(lx!=0&&nxt[lx][x]!=0&&!vis[nxt[lx][x]]){			//原路继续  
		vis[nxt[lx][x]]=1;
		dfs(nxt[lx][x],lx,cnt);
		vis[nxt[lx][x]]=0;
	}
	for(int i=1;i<=m;i++){				//回到站厅换乘，枚举路线  
		if(!mp[i][x]||i==lx)continue;	//当前站点没有这条路线||已经是当前这条路线 
//		if(vis[i][x])continue;
		int tm=t[lx][x]+t[i][x];		//走到展厅+走到下一个路线的站台  
		
		vis[x]=1;
		dfs(nxt[i][x],i,cnt+tm);		 
		vis[x]=0;
	}
}

int dis[N];

vector<pair<int,int>>g[N];

struct node{
	int id,w;
	bool operator>(const node &b)const{
		return this->w>b.w;
	}
};

void dijkstra(int st){
	vector<bool>vs(n+1,0);
	for(int i=0;i<=n;i++)dis[i]=inf;
	priority_queue<node,vector<node>,greater<node>>q;
	q.push({st,0});
	dis[st]=0;
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vs[u])continue;
		vs[u]=1;
		for(auto x:g[u]){
			int v=x.first,w=x.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}

signed main(){
//	freopen("subway3.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read();
	m=read(),n=read(),d=read(),q=read();
	for(int i=1;i<=n;i++)w[i]=read();
	
	for(int i=1;i<=m;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			a[i][j]=read();						//第i条路线第j个站点的id   
			t[i][a[i][j]]=read();				//第i条路线到id的时间 
			mp[i][a[i][j]]=1;					//id可以走第i条路线   
			if(j>1)nxt[i][a[i][j-1]]=a[i][j];	
			//第i条路线下，上一个站台的下一个站台为id  
			if(j>1)pre[i][a[i][j]]=a[i][j-1];
		}
	}
	
	if(0<=C&&C<=6){			//bl 
		while(q--){		
			int x=read(),y=read();
//			for(int i=0;i<=m;i++)for(int j=0;j<=n;j++)vis[i][j]=0;
			for(int i=0;i<=n;i++)vis[i]=0;
			det=y;
			ans=inf;
			vis[x]=1;
			dfs(x,0,0);
			write(ans+w[x]+w[y]);
		}
	}else if(7<=C&&C<=11){	//A	->dij
		//Add edge
		for(int i=1;i<=m;i++){
			if(a[i][2]==0)continue;
			int a1=a[i][1],a2=a[i][2];
			g[a1].push_back({a2,t[i][a1]+t[i][a2]});
			g[a2].push_back({a1,t[i][a1]+t[i][a2]});
		}
		while(q--){
			int x=read(),y=read();
			dijkstra(x);
			write(dis[y]+w[x]+w[y]);
		}
	}else if(12<=C&&C<=19){	//B
		
	}else{					//一般  
		
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


A->dij
9 4 5 20 1
10 10 10 10 10
2 1 1 2 2
2 2 3 3 4
2 3 5 5 8
2 5 6 4 7
1 4
*/
