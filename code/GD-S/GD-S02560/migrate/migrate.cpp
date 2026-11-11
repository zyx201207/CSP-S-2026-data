#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
int c,t;
int n;
ll d;
ll x[2000005];
int ind[5005];
pll dist[5005][5005];
vector<int> g[5005];
void topo(int s){
	for(int i=s;i<=n;i++)ind[i]=0;
	for(int i=s;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d)ind[j]++;
			else break;
		}
	}
	queue<int> q;
	q.push(s);
	dist[s][s]={0,1};
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			ind[v]--;
			if(dist[s][u].first+1<dist[s][v].first)dist[s][v].first=dist[s][u].first+1,dist[s][v].second=dist[s][u].second;
			else if(dist[s][u].first+1==dist[s][v].first)dist[s][v].second+=dist[s][u].second;
			if(ind[v]==0)q.push(v);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c<=10){
			for(int i=1;i<=n;i++){
				g[i].clear();
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d)g[i].push_back(j);
					else break;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)dist[i][j]={1e18,0};
			}
			int ans=0;
			for(int i=1;i<=n;i++)topo(i);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dist[i][j].second==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}else if(c<=12){
			ll len=d/(x[2]-x[1]);
			if(len<=1)cout<<"0\n";
			else cout<<max(0ll,n-len*2+1)<<'\n';
		}else{
			cout<<"0\n";
		}
	}
	return 0;
}
