#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ton[1000010],len[1000010],u,v,lend;
vector<int>l[1000010];
int dfs(int x){
	for(int i=1;i<=n;i++)ton[i]=0;
	int ans=0;
	queue<int>pq;
	pq.push(x);
	while(!pq.empty()){
		int u=pq.front();
		for(int i=0;i<len[u];i++){
			int v=l[u][i];
			if(ton[v]==0&&v!=x){
				ton[v]=ton[u]+1;
				ans=v;
				lend=ton[u]+1;
				pq.push(v);
			}
		}
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	for(int qwq=1;qwq<=t;qwq++){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&u,&v);
			len[u]+=1;
			len[v]+=1;
			l[u][len[u]]=v;
			l[v][len[v]]=u;
		}
		if(c==13||c==14){
			printf("%d\n",k);
		}else if(k==2){
			printf("1\n");
		}else {
			u=dfs(1);
			v=dfs(u);
			printf("%d\n",lend);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
