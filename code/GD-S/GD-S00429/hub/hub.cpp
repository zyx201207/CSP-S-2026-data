#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> G[1005];
struct node{
	int u,v;
};
vector<node> G2;
int fa[1005];
vector<int> v;
int get(int x){
	if(fa[x]==x) return x;
	fa[x]=get(fa[x]);
	return fa[x];
} 
void merge(int x,int y){
	int tx=get(x),ty=get(y);
	if(tx!=ty){
		fa[tx]=ty;
	}
}
int dis[1005];
void bfs(int x){
	queue<int> q;
	q.push(x);
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	while(q.size()){
		int now=q.front();
		q.pop();
//		if(binary_search(v.begin(),v.end(),now)) return ;
		for(int i=0; i<(int)G[now].size(); i++){
			int tx=G[now][i];
			if(dis[tx]>dis[now]+1){
				dis[tx]=dis[now]+1;
				q.push(tx);
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,q;
	scanf("%d %d",&c,&q);
	while(q--){
		G2.clear();
		scanf("%d %d",&n,&k);
		for(int i=1; i<=n; i++) G[i].clear();
		for(int i=1; i<n; i++){
			int x,y;
			scanf("%d %d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
			G2.push_back({x,y});
		}
		int ans=INT_MAX;
		for(int i=1; i<(1<<n); i++){
			v.clear();
			for(int j=0; j<n; j++){
				if((i>>j)&1){
					v.push_back(j+1);
				}
			}
			if((int)v.size()!=k) continue;
			for(int j=1; j<=n; j++) fa[j]=j;
			for(int j=0; j<(int)G2.size(); j++){
				int x=G2[j].u,y=G2[j].v;
				if((i>>(x-1))&1){
					if((i>>(y-1))&1){
						merge(x,y);
					}
				}
			}
			set<int> S;
			for(int j=0; j<(int)v.size(); j++){
				S.insert(get(v[j]));
			}
			if(S.size()>2) continue;
			int M=0;
			for(int j=1; j<=n; j++){
//				if((i>>(j-1))&1){
//					continue;
//				}
				int mm=INT_MAX;
				bfs(j);
				for(int K=1; K<=n; K++){
					if((i>>(K-1))&1){
						mm=min(mm,dis[K]);
					}
				}
				M=max(M,mm);
			}
//			cout<<i<<" "<<M<<endl;
			ans=min(ans,M);
		}
		printf("%d\n",ans);
	}
	return 0; 
}
