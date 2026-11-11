#include<bits/stdc++.h>
#define maxn 10005
#define lll int
using namespace std;
lll n,m;
struct node{
	lll w;
	lll t[maxn];
	bool a[maxn];
}sub[maxn];
lll qq;
lll q[maxn][2];
lll c,d;
lll road[maxn][maxn];
lll o;
lll ans;
void dfs(lll ro,lll tai,lll en,lll anss){
	if(tai==en){
		ans=min(ans,anss+sub[en].w+sub[en].t[ro]);
	}
	else{
		for(int i=1;i<=d;i++){
			if(ro==i){
				for(int j=1;j<road[i][0];j++){
					if(road[i][j]==tai){
						dfs(i,road[i][j+1],en,anss);
						
					}
				}
			}
			else if(sub[tai].a[i]){
				for(int j=1;j<road[i][0];j++){
					if(road[i][j]==tai){
						dfs(i,road[i][j+1],en,anss+sub[tai].t[ro]+sub[tai].t[i]);
						
					}
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d" ,&c,&n,&m,&d,&qq);
	for(int i=1;i<=m;i++){
		scanf("%d",&sub[i].w);
	}
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		road[i][0]=tmp;
		for(int j=1;j<=tmp;j++){
			int tm;
			scanf("%d",&tm);
			road[i][j]=tm;
			sub[tm].a[i]=1;
			scanf("%d",&sub[tm].t[i]);
		}
	}
	for(int i=1;i<=qq;i++){
		scanf("%d %d",&q[i][0],&q[i][1]);
		ans=1e9;
		for(int j=1;j<=d;j++){
			if(sub[i].a[j]){
				dfs(j,q[i][0],q[i][1],sub[q[i][0]].w+sub[q[i][0]].t[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
