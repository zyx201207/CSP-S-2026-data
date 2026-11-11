#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,d,x[2000005],cnt[2000005],viss[2000005],dis[2000005],dis2[2000005],vis[2000005];
vector<int>e[2000005];
void dj(int s){
	priority_queue<pair<int,int> >q;
	for(int i=1;i<=n;i++)	dis[i]=1e18,vis[i]=0;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])	continue;
		vis[u]=1;
		for(int v:e[u]){
			dis[v]=min(dis[v],dis[u]+1);
			q.push({-dis[v],v});
		}
	}
}
void bfs(int s){
	queue<int>q;
	for(int i=1;i<=n;i++)	vis[i]=0,dis2[i]=1e18,cnt[i]=0;
	q.push(s);
	dis2[s]=0;
	cnt[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])	continue;
		vis[u]=1;
		for(int v:e[u]){
			if(dis2[u]+1==dis[v]&&dis2[u]+1<=dis2[v])	cnt[v]+=cnt[u];	
			dis2[v]=min(dis2[v],dis2[u]+1);
			q.push(v);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)	cnt[i]=0;
			for(int i=1;i<=n;i++)	e[i].clear();
			for(int i=1;i<=n;i++)	cin>>x[i];
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i!=j&&abs(x[i]-x[j])<=d)	e[i].push_back(j);
			for(int i=1;i<=n;i++){
				dj(i);
				bfs(i);
//				for(int j=1;j<=n;j++)	if(i!=j)	cout<<i<<" "<<j<<" "<<cnt[j]<<endl;
				for(int j=1;j<i;j++)
					if(cnt[j]==2)	ans++;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	cout<<0<<endl;
	return 0;
}

