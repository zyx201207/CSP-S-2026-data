#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int c,t,n,k,ans=1e9;
int de[N][N];
bool cho[N];
vector<int> e[N];  
void dfs1(int x,int fa,int *d){
//	printf("%d %d\n",x,fa);
//	for(int i=1;i<=2e5;i++) printf("");
	d[x]=d[fa]+1;
	for(int y:e[x]){
		if(y!=fa)
			dfs1(y,x,d);
	}
}
void dfs(int x,int st){
	if(x==k+1){
		//get answer
		int tmp=0;
		for(int i=1;i<=n;i++){
			if(!cho[i]){
				int mi=1e9;
				for(int j=1;j<=n;j++){
					if(cho[j]){
						mi=min(mi,de[i][j]-1);
					}
				}
				tmp=max(mi,tmp);
			}
		}
		ans=min(ans,tmp);
		return ;
	}
	for(int i=st;i<=n-k+x;i++){
		cho[i]=true;
		dfs(x+1,i+1);
		cho[i]=false;
	}
}
//ji de xie feropen
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
//			printf("%d %d %d\n",i,i,i);
			dfs1(i,0,de[i]);
		}
		dfs(1,1);
		printf("%d\n",ans);
	}
	return 0;
}

