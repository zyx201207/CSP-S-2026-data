#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;
int c,n,m,d,q,cnt,A;
int dis[M+N],flag[M+N];
int s[M],book[M],st[M];
int x[Q],y[Q],ans[Q];
struct Node{
	int idx,sum;
};
queue<Node> ac;
struct node{
	int v,w;
};
vector<node> mp[M+N];
vector<int> an[M];
queue<int> p;
void bfs(){
	while(!ac.empty()){
		Node h=ac.front();
		ac.pop();
		flag[h.idx]=h.sum;
		int u=h.idx;
		for(int i=0;i<(int)mp[u].size();++i){
			int v=mp[u][i].v;
			if(!flag[v]){
				ac.push({v,h.sum+1});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%d",&s[i]);
	}for(int i=1,k;i<=n;++i){
		scanf("%d",&k);
		for(int j=1,v,w;j<=k;++j){
			scanf("%d%d",&v,&w);
			A=w;
			mp[v].push_back({m+i,w});
			mp[m+i].push_back({v,w});
		}
	}for(int i=1;i<=q;++i){
		scanf("%d%d",&x[i],&y[i]);
		if(!book[x[i]]&&!book[y[i]]){
			st[++cnt]=x[i];
			an[x[i]].push_back(i);
			book[x[i]]=1;
		}else if(book[x[i]]) an[x[i]].push_back(i);
		else an[y[i]].push_back(i);
	}
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<=m+n;++j){
			dis[j]=0x3f3f3f3f;
			flag[j]=0;
		}dis[st[i]]=0;
		p.push(st[i]);
		while(!p.empty()){
			int u=p.front();
			p.pop();
			flag[u]=0;
			for(int k=0;k<(int)mp[u].size();++k){
				int v=mp[u][k].v,w=mp[u][k].w;
				if(dis[v]>dis[u]+w){
					dis[v]=dis[u]+w;
					if(!flag[v]){
						p.push(v);
						flag[v]=1;
					}
				}
			}
		}for(int j=0;j<(int)an[st[i]].size();++j){
			int idx=an[st[i]][j];
			if(x[idx]==st[i]) ans[idx]=dis[y[idx]];
			else ans[idx]=dis[x[idx]];
		}
	}for(int i=1;i<=q;++i){
		printf("%d\n",ans[i]+s[x[i]]+s[y[i]]);
	}
	
	return 0;
}
