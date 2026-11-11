#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5005,inf=1e18;
int cas;
int n,d,x[N];
struct edge{
	int to,nxt;
}e[N*N];
int hd[N*N],tot;
void add(int u,int v){
	e[++tot]={v,hd[u]};
	hd[u]=tot;
}
int dis[N][N],vis[N],cnt[N][N];
void bfs(int st){
	queue<int>q;
	for(int i=1;i<=n;i++) dis[st][i]=inf,vis[i]=0;
	dis[st][st]=0,cnt[st][st]=1;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[st][v]>dis[st][u]+1){
				dis[st][v]=dis[st][u]+1;
				q.push(v);
			}
			if(dis[st][v]==dis[st][u]+1){
				cnt[st][v]+=cnt[st][u];
			}
		}
	}
}
int ans;
void svA(){
	if(x[2]-x[1]>d){
		cout<<"0\n";
		return;
	}
	else{
		int bs;
		for(int i=2;i<=n;i++){
			if(x[2]-x[1]<i*d){
				bs=i-1;
				break;
			}
		}
		
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	int T;
	cin>>cas>>T;
	while(T--){
		cin>>n>>d;
		tot=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			hd[i]=0;
		}
		if(cas==11||cas==12){
			svA();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt[i][j]=0;
				if(x[j]-x[i]<=d) add(i,j),add(j,i);
			}
		} 
		ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4

5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
