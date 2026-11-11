#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000010];
//int dis[1000010];
//int fol[1000010];
//int sum[1000010];
//void dfs(int x,int fa){
//	fol[x]=fa;
//	dis[x]=dis[fa]+1;
//	for(int i=0;i<v[x].size();++i){
//		if(fa==v[x][i]) continue;
//		dfs(v[x][i],x);
//	}
//}
//int dep[1000010];
//void dfs2(int x,int fa){
//	dep[x]=dep[fa]+1;
//	for(int i=0;i<v[x].size();++i){
//		if(v[x][i]==fa){
//			continue;
//		}
//	}
//}
//int cnt=0,a[1000010],vis[1000010];
//void get(int x){
//	int f=x;
//	while(f!=0){
//		a[++cnt]=f;
//		vis[f]=1;
//		f=fol[f];
//	}
//}
//int calc(int x){
//	int res=0;
//	for(int i=0;i<v[x].size();++i){
//		if(!vis[v[x]])
//	}
//}
int vis[1000010];
int o[1000010],ans;
void dfs2(int x,int fa){
	o[x]=1;
	for(int i=0;i<v[x].size();++i){
		if(v[x][i]==fa) continue;
		if(!vis[v[x][i]]) continue;
		dfs2(v[x][i],x);
	}
}
int dis[1000010];
int n,k;
int u[1000010];
void dfs(int x,int p){
	if(p>k){
		return ;
	}
	if(x==n+1){
		if(p!=k) return ;
		for(int i=1;i<=n;++i){
			o[i]=0;
			dis[i]=1e9;
			u[i]=0;
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(vis[i]&&!o[i]){
				dfs2(i,0);
				cnt++;
			}
			if(cnt>2){
				return ;
			}
		}
		queue<int> q;
		for(int i=1;i<=n;++i){
			if(vis[i]){
				q.push(i);
				dis[i]=0;
			}
		}
		while(q.size()){
			int nd=q.front();
			q.pop();
			if(u[nd]) continue;
			u[nd]=1;
			for(int i=0;i<v[nd].size();++i){
				if(vis[2]==1&&vis[3]==1&&vis[9]==1){
				}
				if(dis[v[nd][i]]<=dis[nd]+1) continue;
				dis[v[nd][i]]=dis[nd]+1;
				q.push(v[nd][i]);
			}
		}
		int maxn=0;
		for(int i=1;i<=n;++i){
			maxn=max(maxn,dis[i]);
		}
		ans=min(ans,maxn);
		return ;
	}
	dfs(x+1,p);
	vis[x]=1;
	dfs(x+1,p+1);
	vis[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
//		dis[0]=0;
//		dfs(1,0);
//		int y=0;
//		for(int i=1;i<=n;++i){
//			if(dis[y]<dis[i]){
//				y=i;
//			}
//		}
//		dis[0]=0;
//		dfs(y,0);
//		for(int i=1;i<=n;++i){
//			if(dis[y]<dis[i]){
//				y=i;
//			}
//		}
//		
//		cnt=0;
//		get(y);
//		for(int i=1;i<=cnt;++i){
//			calc(a[i]);
//		}
		ans=1e9;
		dfs(1,0);
		printf("%d\n",ans);
		for(int i=1;i<=n;++i){
			v[i].clear();
//			dis[i]=0;
			vis[i]=0;
		}
	}
	return 0;
}
