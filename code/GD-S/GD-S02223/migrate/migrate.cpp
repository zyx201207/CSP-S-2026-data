#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=5005;

struct node{
	int v,w;
	bool operator <(const node& x)const{
		return w>x.w;
	}
};
vector<int>g[N];
int c,t,n,d,x[N],cnt[N],dis[N],y[2000005];
bool vis[N];

void dijkstra(int s){
	memset(cnt,0,sizeof cnt);
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	queue<node>q;
	q.push({s,0});
	dis[s]=0;
	cnt[s]=1;
	while(!q.empty()){
		node x=q.front();
		q.pop();
		int u=x.v;
		for(int v:g[u]){
			if(dis[v]>dis[u]+1){
				cnt[v]=cnt[u];
				dis[v]=dis[u]+1;
				q.push({v,dis[v]});
			}
			else if(dis[v]==dis[u]+1)
				cnt[v]+=cnt[u];
		}
	}
}

signed main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c<=10){
			for(int i=1;i<=n;++i){
				cin>>x[i];
				g[i].clear();
			}
			for(int i=1;i<=n;++i)
				for(int j=i+1;j<=n;++j)
					if(x[j]-x[i]<=d){
						g[i].push_back(j);
					}	
			int ans=0;
			for(int i=1;i<=n;++i){
				dijkstra(i);
				for(int j=i;j<=n;++j)
					if(cnt[j]==2)
						++ans;
			}
			cout<<ans<<"\n";
		}
		else{
			int ans=0;
			for(int i=1;i<=n;++i)
				cin>>y[i];
			int kk=d/(y[2]-y[1]);
			if(kk==0||kk==1)cout<<"0\n";
			else cout<<max(0ll,n-(kk*2-1))<<"\n";
		}
	}
}
