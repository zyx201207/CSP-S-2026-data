#include<bits/stdc++.h>
using namespace std;
const int N=5000+10;
vector<int> g[N];
long long a[N],dis[N],dp[N][N],ans;
int n,d;
bool vis[N];

void dfs(int s){
	memset(dis,0,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i];
//			cout<<x<<" "<<y<<"\n";
			if(vis[y]){
				dis[y]=dis[x]+1;
				dp[s][y]=1;
				q.push(y);
				vis[y]=true;
			}
			else if(dis[x]+1==dis[y]){
				dp[s][y]++;
//				cout<<x<<" "<<y<<"\n";
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==s) continue;
		if(dp[s][i]==2){
			ans++;
		}
	}
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(abs(a[i]-a[j])<=d){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
