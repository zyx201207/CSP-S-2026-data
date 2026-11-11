#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,t;
int n,d;
int a[N];
int head[N],to[N],nxt[N];
int val[N];
int len;
void add(int x,int y,int z){
	nxt[++len]=head[x];
	head[x]=len;
	to[len]=y;
	val[len]=z;
}
struct node{
	int id;
	int dis;
	bool operator<(const node&x)const{
		return x.dis<dis;
	}
};
priority_queue<node>q;
int dis[N];
int vis[N];
int cnt[N];
void dij(int s){
	for(int i=1;i<=n;i++)dis[i]=1e12,vis[i]=cnt[i]=0;
	dis[s]=0;
	q.push({s,dis[s]});
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int t=to[i];
			if(dis[t]>dis[u]+val[i]){
				dis[t]=dis[u]+val[i];
				cnt[t]=cnt[u];
				if(!vis[t]){
					q.push({t,dis[t]});
				}
			}else if(dis[t]==dis[u]+val[i]){
				cnt[t]++;
			}
		}
	}
}
int ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n>=2e6){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(abs(a[i]-a[j])<=d){
					add(i,j,1);
				}
			}
		}
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==1)ans++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
		memset(head,0,sizeof(head));
	}
	return 0;
}
