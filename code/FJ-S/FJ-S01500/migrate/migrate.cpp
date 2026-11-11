#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define ll long long
int c,t,n,d;
ll a[N],dp[N],f[N],sum[N];
int nxt[N],pre[N];
ll ans;
int dis[305][305];
ll cnt[305][305];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void dijkstra(int s){
	q.push({0,s});
	pair<int,int>now;
	int u,w;
	while(!q.empty()){
		now=q.top();
		q.pop();
		u=now.second,w=now.first;
		if(w!=dis[s][u]) continue;
		for(int v=pre[u];v<=nxt[u];v++){
			if(v==u) continue;
			if(dis[s][v]>dis[s][u]+1){
				dis[s][v]=dis[s][u]+1;
				cnt[s][v]=cnt[s][u];
				q.push({dis[s][v],v});
			}
			else if(dis[s][v]==dis[s][u]+1) cnt[s][v]+=cnt[s][u];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			nxt[i]=pre[i]=i,dp[i]=f[i]=0;
		}	
		for(int i=1,j=1;i<=n;i++){
			j=max(j,i);
			while(j<n&&a[j+1]-a[i]<=d){
				pre[j]=min(pre[j],i);
			//	cerr<<i<<" "<<j<<"\n";
				j++;
			}
			nxt[i]=j,pre[j]=min(pre[j],i);
		//	cerr<<nxt[i]<<" "<<pre[i]<<"\n";
		}
		if(c<=6){
			memset(dis,0x3f,sizeof(dis));
			memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=n;i++){
				dis[i][i]=0;cnt[i][i]=1;dijkstra(i);
			}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(cnt[i][j]==2) ans++;
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}

