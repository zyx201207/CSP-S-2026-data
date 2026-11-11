#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+10;
ll dis[maxn];
int cnt[maxn];
int head[maxn],to[maxn*2],nxt[maxn*2];
ll w[maxn*2];
int cnta=1;
bool vis[maxn];
ll x[maxn];
int c,t;
int n;
ll d;

struct node{
	int id;
	ll c;
	bool operator<(const node& a)const{
		return c<a.c;
	}
};
void ad(int u,int v,int c){
	nxt[cnta]=head[u];
	to[cnta]=v;
	w[cnta]=c;
	head[u]=cnta++;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+1+n);
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int c=abs(x[i]-x[j]);
				ad(i,j,c);
			}
		}
		ll minn=LLONG_MAX;

		for(int i=1;i<=n-3;i++){
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			queue<node>q;
			dis[i]=0;
			q.push({i,0});
			while(!q.empty()){
				node cur=q.front();
				q.pop();
				int u=cur.id;
				if(!vis[u]){
					vis[u]=true;
					cnt[u]++;
				}
				for(int e=head[u];e!=0;e=nxt[e]){
					int v=to[e];
					ll c=w[e];
					if(c>d){
						continue;
					}
					if(!vis[v]&&dis[v]>dis[u]+1){
						dis[v]=dis[u]+c;
						q.push({v,dis[v]});
					}
					else if(vis[v]){
						if(dis[v]==dis[u]+1){
							cnt[v]++;
						}
					}
				}
			}
			ll min_dis=LLONG_MAX;
			ll cnt_d=0;
			for(int j=i+3;j<=n;j++){
				min_dis=min(min_dis,dis[j]);
			}
			if(min_dis<minn){
				for(int j=i+3;j<=n;j++){
					if(dis[j]==min_dis){
						if(cnt[j]==2){
							cnt_d++;
						}
					}
				}
				ans=cnt_d;
				minn=min_dis;				
			}
			else if(min_dis==minn){
				for(int j=i+3;j<=n;j++){
					if(dis[j]==min_dis){
						if(cnt[j]==2){
							cnt_d++;
						}
					}
				}
				ans+=cnt_d;
			}
		}

		cout<<ans<<'\n';
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

要求最短路径，长度要最短 

*/
