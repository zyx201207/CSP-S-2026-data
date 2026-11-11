#include<bits/stdc++.h>
using namespace std;
int C,N,M,D,Q,k[510],ans=INT_MAX;
int W[500010],dist[410][410];
int A[510][410],T[510][410];
bool vis[510];
void init(){
	for(int i=1;i<=400;i++)
		for(int j=1;j<=400;j++){
			if(i==j) dist[i][j]=0;
			else dist[i][j]=0x3f3f3f3f;
		}
}
void DFS(int start,int end,int sum){
	if(start==end){
		ans=min(ans,sum);
		return ;
	}
	sum+=T[start][start];
	vis[start]=true;
	for(int j=1;j<=k[start];j++){
		int nx=A[start][j];
		if(vis[nx]) continue;
		vis[nx]=true;
		DFS(nx,end,sum+T[start][nx]);
		vis[nx]=false;
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&N,&M,&D,&Q);
	for(int i=1;i<=M;i++)
		scanf("%d",&W[i]);	
	init();
	for(int i=1;i<=N;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int t;
			scanf("%d%d",&A[i][j],&t);
			T[i][A[i][j]]=t;
		}
	}
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		DFS(x,y,W[x]+W[y]);
		printf("%d\n",ans);
	}
    return 0;
} 

