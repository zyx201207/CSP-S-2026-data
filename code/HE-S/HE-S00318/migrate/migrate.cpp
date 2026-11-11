#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int x[N],dist[N],cnt[N];
vector<int>e[N];
int n,d;
int bfs(int s){
	queue<int>q;
	for(int i=1;i<=n;i++)dist[i]=-1,cnt[i]=0;
	dist[s]=0;
	cnt[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int j:e[u]){
			if(dist[j]==-1){
				dist[j]=dist[u]+1;
				cnt[j]+=cnt[u];
				q.push(j);
			}
			else if(dist[j]==dist[u]+1)cnt[j]+=cnt[u];
		}
	}
	int res=0;
	for(int i=s+1;i<=n;i++){
		if(cnt[i]==2)res++;
	}
	return res;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			e[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=bfs(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
