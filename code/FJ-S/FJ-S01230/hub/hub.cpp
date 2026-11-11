#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
struct edge{
	int to,nxt;
}e_list[N*2];
int head[N],e_num;
struct p{
	int x,w;
};
void add(int u,int v){
	e_list[++e_num].nxt=head[u];
	e_list[e_num].to=v;
	head[u]=e_num;
}
bool cho[N],vis[N];
int fa[N],dis[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
queue<p>q;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		int ans=1e9;
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			for(int j=0;j<n;j++){
				if(i>>j&1){
					fa[j+1]=j+1;
					cho[j+1]=1;
					cnt++;
				}
				else cho[j+1]=fa[j+1]=0;
			}
			if(cnt!=k)continue;
			
			for(int j=1;j<=n;j++){
				if(cho[j]){
					for(int k=head[j];k;k=e_list[k].nxt){
						int to=e_list[k].to;
						if(cho[to]){
							fa[find(j)]=find(to);
						}
					}
				}
			}
			int r1=-1,r2=-1,flag=1;
			for(int j=1;j<=n;j++){
				if(cho[j]){
					int fj=find(j);
					if(r1==-1)r1=fj;
					else if(fj!=r1){
						if(r2==-1)r2=fj;
						else if(r2!=fj)flag=0;
					}
				}
			}
			if(!flag)continue;
			for(int j=1;j<=n;j++){
				if(cho[j])q.push({j,0});
				vis[j]=0;
			}
			while(!q.empty()){
				int x=q.front().x,w=q.front().w;q.pop();
				if(vis[x])continue;
				vis[x]=1,dis[x]=w;
				for(int j=head[x];j;j=e_list[j].nxt){
					int to=e_list[j].to;
					if(!vis[to])q.push({to,w+1});
				}
			}
			int len=0;
			for(int j=1;j<=n;j++)len=max(len,dis[j]);
			ans=min(ans,len);
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)head[i]=0;
	}
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/