#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;
int n,k,ans=0x7777777f;
struct edge{
	int to,nxt;
}e[114514];
int head[114514],tot=0;bool mp[1145][1145],vis[114514];
int arr[114514];int dist[114514];
void add(int u,int v){
	e[++tot]=(edge){v,head[u]};
	head[u]=tot;
	return;
}
void spfa(int st){
	memset(dist,0x3f,sizeof(dist));
	dist[st]=0;
	queue<int> qu;qu.push(st);
	while(!qu.empty()){
		int nw=qu.front();qu.pop();
		for(int i=head[nw];i;i=e[i].nxt){
			int u=e[i].to;
			if(dist[u]>dist[nw]+e[i].to){
				dist[u]=dist[nw]+e[i].to;
				qu.push(u);
			}
		}	
	}
}
void dfs(int num,int cnt){
	if(num==k){
		
		int maxd=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			spfa(i);
			int mind=0x7777777f;
			for(int j=0;j<k;j++){
				mind=min(mind,dist[arr[j]]);
			}
			maxd=max(maxd,mind);
		}
		//cout<<maxd<<' ';
		ans=min(ans,maxd);
		return;
	}int tcnt=cnt;
	for(int i=arr[max(0,num-1)]+1;i<=n;i++){
		cnt=tcnt;
		if(vis[i])continue;
		cnt++;for(int j=0;j<num;j++){if(mp[arr[j]][i]){cnt--;break;}}
		if(cnt>2)return;
		arr[num]=i;vis[i]=1;
		dfs(num+1,cnt);
		vis[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		memset(arr,0,sizeof(arr));
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&k);
		for(int i=0;i<n-1;i++){
			int u,v;scanf("%d%d",&u,&v);
			add(u,v);add(v,u);
			mp[u][v]=mp[v][u]=1;
		}
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}


//freopen
// wyx,I love u
