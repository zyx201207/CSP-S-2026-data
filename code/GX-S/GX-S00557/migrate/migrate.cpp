#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,INF=N;
int c,T;
int n,d,x[N];
vector<int> e[N];
int dis[N],vis[N],cnt[N];
int ans;
void clr(){
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	ans=0;
}
void bfs(int v0){
	queue<int> q;
	for(int i=1;i<=n;i++){
		dis[i]=INF;
		vis[i]=0;
		cnt[i]=0;
	}
	dis[v0]=0;
	q.push(v0);
	vis[v0]=1;
	cnt[v0]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(!vis[v]){
				vis[v]=1;
				cnt[v]=cnt[u];
				dis[v]=dis[u]+1;
				q.push(v);
			}
			else if(dis[u]+1==dis[v]) cnt[v]+=cnt[u];
		}
	}
	for(int i=1;i<=n;i++)
		if(cnt[i]==2){
			//cout<<v0<<" "<<i<<"\n";
			ans++;
		}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c==11 || c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			int gc=x[2]-x[1];
			int r=d/gc;
			if(d==1) cout<<0<<"\n";
			else cout<<max(0ll,n-(2*r-1))<<"\n";
		}
	}
	else{
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(x[i]-x[j])<=d){
						e[i].push_back(j);
						e[j].push_back(i);
					}
				}
			}
			for(int i=1;i<=n;i++)
				bfs(i);
			ans/=2;
			cout<<ans<<"\n";
			clr();
		}
	}
	
	return 0;
}
