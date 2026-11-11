#include<bits/stdc++.h>
using namespace std;

struct node{
	int dis,v;
};

int dis[5010],used[5010],n,cnt[5010];
long long d,a[5010];

vector<int> e[5010];
void dist(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(used,0,sizeof(used));
	queue<node> q;
	q.push({0,s});
	cnt[s]=1;
	dis[s]=0;
	while(!q.empty()){
		int u=q.front().v;
		q.pop();
		if(used[u]) continue;
		used[u]=1;
		for(auto v:e[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				if(!used[v]) q.push({dis[v],v});
			}else if(dis[v]==dis[u]+1){
				cnt[v]+=cnt[u];
				if(cnt[v]>=3) cnt[v]=3;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i = 1;i <= n;i++) cin>>a[i],e[i].clear();
		for(int i = 1;i <= n;i++) for(int j = i + 1;j<=n&&a[j]-a[i]<=d;j++) e[i].push_back(j);
		for(int i = 1;i <= n;i++){
			dist(i);
			for(int j = i+1;j <= n;j++) ans+=(cnt[j]==2);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
