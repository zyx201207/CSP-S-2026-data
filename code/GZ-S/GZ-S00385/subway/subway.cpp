//GZ-S00385
//张哲铭
//毕节梁才学校
#include<bits/stdc++.h>
using namespace std;
/*
考虑floyd
主要在建边上面（无重边） 
同一个地铁站内的建边就行了
不对，怎么这么多个站啊
不管了，直接LCA加链式前向星 
忘了边权不是1，天塌了 
完了17:04了，只能打暴力了 
*/
int c,n,m,d,Q;
int W[500+10];
/*int to[1000000+10];
int nt[1000000+10];
int h[1000000+10];
int w[1000000+10];
int idx;
void add(int x,int y,int z){
	to[idx]=y;
	nt[idx]=h[x];
	w[idx]=z;
	h[x]=idx;
	idx++;
} */
int g[3010][3010]; 


/*int depth[1000000+10];
int zu[1000000+10][22];//20
bool v[1000000+10];
void dfs(int u,int fa){
	depth[u]=depth[fa]+1;
	zu[u][0]=fa;
	v[u]=true;
	for(int k=1;k<=20;k++)zu[u][k]=zu[zu[u][k-1]][k-1];
	for(int i=h[u];i!=-1;i=nt[i]){
		int j=to[i];
		if(v[j])continue;
		dfs(j,u);
	}
}
int LCA(int x,int y){
	if(depth[y]>depth[x])swap(x,y);
	for(int k=20;k>=0;k--){
		if(depth[zu[x][k]]>=depth[y])x=zu[x][k];
	}
	if(x==y)return x;
	for(int k=20;k>=0;k--){
		if(depth[zu[x][k]]!=depth[zu[y][k]]){
			x=zu[x][k];
			y=zu[y][k];
		}
	}
	return zu[x][0];
}*/
int ma;
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	
//	memset(h,-1,sizeof(h));
	memset(g,0x3f,sizeof(g));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)scanf("%d",&W[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		vector<int>a;
		vector<int>b;
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			a.push_back(x);
			b.push_back(y);
		}
		for(int e=0;e<k;e++){
			for(int f=e+1;f<k;f++){
				/*add(a[e],a[f],b[e]+b[f]);
				add(a[f],a[e],b[e]+b[f]);*/
				g[a[f]][a[e]]=min(b[e]+b[f],g[a[f]][a[e]]);
				g[a[e]][a[f]]=min(b[e]+b[f],g[a[e]][a[f]]);
				ma=max(max(a[e],a[f]),ma);
			}
		} 
	}
//	dfs(1,0);
	for(int k=1;k<=ma;k++){
		for(int i=1;i<=ma;i++){
			g[i][i]=0;
			for(int j=1;j<=ma;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				g[j][i]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		/*int anc=LCA(x,y);
		printf("%d\n",(depth[x]+depth[y]-depth[anc]*2)+W[x]+W[y]);*/
		printf("%d\n",g[x][y]+W[x]+W[y]);
	}

	return 0;
}
