#include<bits/stdc++.h>
#define fi first
#define se second
#define pi pair<int,int>
#define lg(x) (63-__builtin_clzll(x))
typedef long long ll;
using namespace std;
const int N=2e6+100;
const int inf=0x3f3f3f3f;
int c,t;
int n,k;
vector<int> a[N];
int dis[N];
bool vis[N];
void dfs(int u){
	if(!vis[u]) return ;
	vis[u]=false;
	for(int v:a[u]) dfs(v);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) a[i].clear();
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		int tot=(1<<n)-1;
		int ans=inf;
		if(c==7){
			for(int s0=1;s0<=n;s0++) for(int s1=s0+1;s1<=n;s1++){
				queue<int> q;
				for(int i=1;i<=n;i++) dis[i]=inf;
				dis[s0]=dis[s1]=0;
				q.push(s0),q.push(s1);
				while(q.size()){
					int u=q.front();
					q.pop();
					for(auto v:a[u]){
						if(dis[v]>dis[u]+1){
							dis[v]=dis[u]+1;
							q.push(v);
						}
					}
				}
				int res=0;
				for(int i=1;i<=n;i++) res=max(res,dis[i]);
				ans=min(res,ans);
			} 
		}else{
			for(int s=0;s<=tot;s++){
				if(__builtin_popcount(s)>k) continue;
				queue<int> q;
				for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=false;
				for(int i=1;i<=n;i++)
					if(s>>(i-1)&1){
						dis[i]=0;
						q.push(i);
						vis[i]=true;
					}
				int cnt=0;
				for(int i=1;i<=n;i++) if(vis[i]) cnt++,dfs(i); 
				if(cnt>2) continue;
				while(q.size()){
					int u=q.front();
					q.pop();
					for(auto v:a[u]){
						if(dis[v]>dis[u]+1){
							dis[v]=dis[u]+1;
							q.push(v);
						}
					}
				}
				int res=0;
				for(int i=1;i<=n;i++) res=max(res,dis[i]);
				ans=min(res,ans);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
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
*/
