#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
const int N=505;
int m,n,d,p,x;
ll y;
int c;
int w[M],k[N];
vector<pair<int,int> > a[N+M];
ll diss[N][N];
ll dis[M+N];
bool vis[M+N];
priority_queue<pair<ll,int> > q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)diss[i][j]=1e18;
		diss[i][i]=0;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back({x+n,y});
			a[x+n].push_back({i,y});
		}
	}
	for(int s=1;s<=n;s++){
		for(int i=1;i<=m+n;i++){
			dis[i]=1e18;vis[i]=0;
		}
		dis[s]=0;
		q.push({0,s});
		while(q.size()){
			y=q.top().first;
			x=q.top().second;
			q.pop();
			if(vis[x])continue;
			vis[x]=1;
			if(x<=n){
				diss[x][s]=diss[s][x]=dis[x];
			}
			for(auto j:a[x]){
				if(vis[j.first])continue;
				if(dis[j.first]>y+j.second){
					dis[j.first]=y+j.second;
					q.push({dis[j.first],j.first});
				}
			} 
		}
		
	}
	
	while(p--){long long ans=1e18;
		cin>>x>>y;
		for(auto i:a[x+n]){
			for(auto j:a[y+n]){
				ans=min(ans,diss[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
