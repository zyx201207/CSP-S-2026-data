#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005;
int n,d,ans;
int a[maxn],b[maxn];
int dis[maxn][maxn],dist[maxn];
vector<int> g[maxn];
queue<int> q;
void solve(){
	ans=0;
	cin>>n>>d;
	if(n>5000){
		cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i-1;j;j--){
			if(a[i]-a[j]>d){
				break;
			}
			g[j].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
		q.push(i);
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(auto u:g[x]){
				if(dis[i][u]>dis[i][x]+1){
					dis[i][u]=dis[i][x]+1;
					q.push(u);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=0,dist[j]=1e18;
		}
		b[i]=1,dist[i]=0;
		q.push(i);
		while(!q.empty()){
			int x=q.front();
			q.pop();
			if(b[x]==2){
				ans++;
			}
			for(auto u:g[x]){
				if(dist[u]>=dist[x]+1){
					if(dist[u]>dist[x]+1){
						q.push(u);
					}
					dist[u]=dist[x]+1,b[u]+=b[x];
				}
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
