#include<bits/stdc++.h>
#define ll long long
#define fi(x) freopen(x".in","r",stdin)
#define fo(x) freopen(x".out","w",stdout)
#define wc(x) fi(x);fo(x)
#define F first
#define S second
using namespace std;
const int N=5010;
int c,t,n;
ll d,x[N],dis[N][N],ans,vis[N],sum[N][N];
vector<int> e[N]; 
void bfs(int a) {
	for(int i=1;i<=n;i++) vis[i]=0;
	queue<pair<int,int>> q;
	q.push({0,a}); 
	dis[a][a]=0;
	while(!q.empty()) {
		pair<int,int> now=q.front();
		q.pop();
		for(auto i:e[now.S]) {
			//cout<<now.F<<' '<<now.S;
			if(dis[a][i]>now.F+1) {
				vis[i]=1;
				dis[a][i]=now.F+1;
				q.push({now.F+1,i});
			} else if(dis[a][i]==now.F+1){
				vis[i]++;
				q.push({now.F+1,i});
			} 			
		}
	}
	for(int i=1;i<=n;i++) if(i!=a&&vis[i]==2) ans++; 
	
}
void solve() {
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++) e[i].clear(); 
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
	//for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1; i<=n; i++) cin>>x[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j&&abs(x[i]-x[j])<=d) e[i].push_back(j),dis[i][j]=1;
	/*for(int k=1;k<=n;k++) {
		for(int i=1;i<=k;i++) {
			for(int j=k+1;j<=n;j++) {
				if(dis[i][j]>dis[i][k]+dis[k][j]) {
					sum[i][j]=sum[i][k]*sum[k][j];
					dis[i][j]=dis[i][k]+dis[k][j];
				} else if(dis[i][j]==dis[i][k]+dis[k][j]) {
					sum[i][j]+=sum[i][k]*sum[k][j]
				}
			}
		}
	}*/
	for(int i=1;i<=n;i++) {
		bfs(i);
	}
	//ll sum=0;
	//for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(ans[i][j]==2) sum++;
	cout<<ans/2<<'\n';
	return; 
}
int main() {
	wc("migrate");
	//fi("migrate1");
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

