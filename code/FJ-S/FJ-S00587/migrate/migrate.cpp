#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,D,a[2000005],cnt[2000005],d[2000005],ans,t,c;
vector<int>adj[2000005];
void bfs(int k){
	memset(cnt,0,sizeof(cnt));
	memset(d,0x3f,sizeof(d));
	d[k]=0;
	cnt[k]=1;
	queue<int>q;
	q.push(k);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:adj[u])
			if(d[v]>d[u]+1){
				cnt[v]=cnt[u];
				d[v]=d[u]+1;
				q.push(v);
			}else if(d[v]==d[u]+1)
				cnt[v]+=cnt[u];
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++)adj[i].clear();
		cin>>n>>D;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=D)
					adj[i].emplace_back(j);
		ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++)
				ans+=(cnt[j]==2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
