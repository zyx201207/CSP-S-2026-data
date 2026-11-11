#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define int long long
#define x first
#define y second
const int mod=1e9+7;
const int N=2e6+50;
const int M=1e7+50;
const int INF=2e18;
#define endl '\n'
#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int c,t;
int n,m;
int a[N]={};
struct edge{
	int u,v,nxt;
}e[M];
int head[N]={};
int tot=0;
void addedge(int u,int v){
	e[++tot]=edge{u,v,head[u]};
	head[u]=tot; 
}
struct node{
	int u,dis;
	bool operator<(const node &cmp)const{
		return dis>cmp.dis;
	}
};
bool vis[N]={};
int dis[N]={};
int cnt[N]={};
void dijkstra(int s,int t){
	for(int i=1;i<=n;i++){
		cnt[i]=0;
		dis[i]=INF;
		vis[i]=0;
	}
	priority_queue<node> q;
	q.push({s,0});
	dis[s]=0;
	cnt[s]=1;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push({v,dis[v]});
			}else if(dis[v]==dis[u]+1){
				cnt[v]+=cnt[u];
			}
		} 
	}
}
bool check(int x,int y){
	dijkstra(x,y);
	if(cnt[y]==2){
		return 1;
	}else{
		return 0;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IO;
	cin>>c>>t;
	while(t--){
		tot=0;
		memset(head,0,sizeof head);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int pos=upper_bound(a+1,a+n+1,a[i]+m)-a;
//			cout<<i<<endl; 
			pos--;	
			for(int j=i+1;j<=pos;j++){
//				cout<<j<<" ";
				addedge(i,j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
//			cout<<i<<endl;
			for(int j=i+1;j<=n;j++){
//				cout<<j<<" ";
				if(check(i,j)){
					ans++;	
				}
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}

