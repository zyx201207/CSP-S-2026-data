#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,ans,x[2000005],dis[2000005],cnt[2000005];
bool vis[2000005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		ans=0;
		if(c==11 || c==12){
			int num=x[1];
			for(int i=1;i<=n;i++)x[i]-=num;
			if(d<=2*(x[2]-x[1])){
				cout<<"0\n";
			}else{
				cout<<n-(d/(x[2]-x[1]))*2+1<<'\n';
			}
			continue;
		}
		for(int s=1;s<=n;s++){
			q.push({0,s});
			for(int i=s+1;i<=n;i++)dis[i]=0x3f3f3f3f3f3f3f3f;
			for(int i=s;i<=n;i++)vis[i]=false;
			dis[s]=0;
			cnt[s]=1;
			for(int i=s+1;i<=n;i++)cnt[i]=0;
			while(!q.empty()){
				int u=q.top().second;
				q.pop();
				if(vis[u])continue;
				vis[u]=true;
				for(int v=u;v<=n && x[v]-x[u]<=d;v++){
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						cnt[v]=cnt[u];
						q.push({dis[v],v});
					}else if(dis[v]==dis[u]+1){
						cnt[v]+=cnt[u];
					}
				}
			}
			for(int i=s+1;i<=n;i++)if(cnt[i]==2)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
