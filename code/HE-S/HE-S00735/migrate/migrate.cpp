#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
struct fs{
	int net,to;
};
struct zhi{
	int vu[5010],w_id;
	fs w[25000010];
	void jt(int a,int b){
		w_id++;
		w[w_id].net=vu[a];
		w[w_id].to=b;
		vu[a]=w_id;
	}
	void c(int n){
		for(int i=1;i<=n;i++){
			vu[i]=0;
		}
		w_id=0;
	}
};
zhi g;
long long ask[2000010];
int dis[2000010],vis[2000010];
int bfs(int v){
	for(int i=1;i<=n;i++){
		dis[i]=0x3f3f3f3f;
		vis[i]=0;
	}
	queue<int> q;
	q.push(v);
	dis[v]=0;
	while(!q.empty()){
		int id=q.front();
		q.pop();
		for(int i=g.vu[id];i;i=g.w[i].net){
			int u=g.w[i].to;
			if(dis[u]>dis[id]+1){
				vis[u]=1;
				dis[u]=dis[id]+1;
				q.push(u);	
			}else if(dis[u]==dis[id]+1){
				q.push(u);	
				vis[u]++;
			}
		}
	}
	int cnt=0;
	for(int i=v;i<=n;i++){
		if(vis[i]==2) cnt++;
	}
//	cout<<endl<<v<<endl;
//	cout<<"dis ";
//	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<" ";
//	}
//	cout<<endl<<"vis";
//	for(int i=1;i<=n;i++){
//		cout<<vis[i]<<" ";
//	}
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d %lld",&n,&d);
		g.c(n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&ask[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(ask[j]-ask[i]<=d){
					g.jt(i,j);
				}
			}
		}
		long long an=0;
		for(int i=1;i<=n;i++){
			an+=bfs(i);
		}
		cout<<an<<endl;
	} 
	return 0;
}
