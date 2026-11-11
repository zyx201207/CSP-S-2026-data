#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll k=0,f=1;
	int c=getchar();
	for(;!isdigit(c);c=getchar()){if(c=='-')f=-1;}
	for(;isdigit(c);c=getchar()){k=k*10+(c&15);}
	return f*k;
}
const int maxn=1e3+100;
int c,t;
int n,k;
vector<int>a[maxn];
int fa[maxn];
int siz[maxn];
vector<int>path;
bool vis[maxn];
int st[maxn][25];
int de[maxn];
int ans=maxn+100;
void clea(){
	for(int i=1;i<=n;i++){
		a[i].clear();
	}
	fill(vis+1,vis+1+n,0);
	fill(de,de+n+1,0);
	ans=maxn+100;
}
void initfa(){
	for(int i=1;i<=n;i++){
		fa[i]=i;siz[i]=1;
	}
}
//并查集部分 
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]==find(fa[x]);
}
void uion(int x,int y,int &cnt){
	int rx=find(x),ry=find(y);
	if(rx==ry) return; 
	if(siz[rx]>siz[ry]){
		swap(rx,ry);
	}
	fa[rx]=ry;
	cnt--;
	siz[ry]+=siz[rx];
}
//=========lca部分 
void dfss(int u,int f){
	st[u][0]=f;de[u]=de[f]+1;
	for(int v:a[u]){
		if(v==f)continue;
		dfss(v,u);
	}
}
//初始化st表 
void initst(){
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			st[i][j]=st[st[i][j-1]][j-1];
		}
	}
}
int lca(int x,int y){
	if(de[x]<de[y]){
		swap(x,y);
	}
	for(int j=19;j>=0;j--){
		if(de[st[x][j]]>=de[y]){
			x=st[x][j];
		}
	}
	if(x==y)return x;
	for(int j=19;j>=0;j--){
		if(st[x][j]!=st[y][j]){
			x=st[x][j],y=st[y][j];
		}
	}
	return st[x][0];
}
int dis(int x,int y){
//	if(de[x]<de[y])swap(x,y);
	int lxa=lca(x,y);
	return de[x]-de[lxa]+de[y]-de[lxa];
}
//递归部分 
void dfs(int x,int tmp){
	if(x>1+n) return;
	if(tmp>k){
		initfa();
		int cnt=k;
//		printf("path\n");
		for(int j:path){
//			printf("%d ",j);
			for(int v:a[j]){
				if(!vis[v])continue;
				uion(v,j,cnt);
			}
		}
//		printf("\n");
		if(cnt>2) return;
		//计算通勤半径 
		int rr=0;
		for(int i=1;i<=n;i++){
			int res=maxn+100;
			for(int j:path){
				res=min(res,dis(i,j));
			}
			rr=max(res,rr);
		}
//		printf("	rr %d\n",rr);
		ans=min(ans,rr);
//		printf("	ans %d\n",ans);
		return;
	}
	vis[x]=1;
	path.push_back(x);
	dfs(x+1,tmp+1);
	vis[x]=0;path.pop_back();
	dfs(x+1,tmp);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		clea();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			a[u].push_back(v);
			a[v].push_back(u);
		}
		//两次bfs初始化距离
		dfss(1,0);
		initst();
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<=5;j++){
//				printf("%d ",st[i][j]);
//			}
//			printf("\n");
//		}
		//便利选点
		dfs(1,1);
		printf("%lld\n",ans);
	} 
	return 0;
}
