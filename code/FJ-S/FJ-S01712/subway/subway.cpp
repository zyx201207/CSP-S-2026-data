#include<bits/stdc++.h>
#define ll long long
#define N 600
#define M 500010
using namespace std;
ll n,m,D,Q,inf;
ll w[M];
vector<pair<ll,ll> >v[N],sub[M];
ll bb[N][N];
bool vis[N];
priority_queue<pair<ll,ll> >q;
inline void add(ll x,ll y){
	ll i,j,l=(v[x].size()),r=(v[y].size());
	for(i=j=0;i<l;i++){
		while(j<r&&v[x][i].first>v[y][j].first)j++;
		if(j==r)return;
		if(v[x][i].first==v[y][j].first)bb[x][y]=bb[y][x]=min(bb[x][y],v[x][i].second+v[y][j].second);
	}
}
inline void get(ll rot){
	ll i,x,y;
	for(i=1;i<=n;i++)q.push(make_pair(-bb[rot][i],i));
	memset(vis,0,sizeof(vis));
	vis[rot]=1;
	while(!q.empty()){
		x=(q.top().second),q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(y=1;y<=n;y++){
			if(bb[rot][y]>bb[rot][x]+bb[x][y]){
				bb[rot][y]=bb[y][rot]=bb[rot][x]+bb[x][y];
				q.push(make_pair(-bb[rot][y],y));
			}
		}
	}
}
inline ll work(ll x,ll y){
	ll i,j,l=(sub[x].size()),r=(sub[y].size()),ans=inf;
	for(i=0;i<l;i++)
		for(j=0;j<r;j++)
			ans=min(ans,sub[x][i].second+sub[y][j].second+w[x]+w[y]+bb[sub[x][i].first][sub[y][j].first]);
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(bb,0x3f,sizeof(bb));
	inf=bb[0][0];
	ll i,j,k,x,y;
	cin>>n>>n>>m>>D>>Q;
	for(i=1;i<=n;i++)bb[i][i]=0;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>j;
		while(j--){
			cin>>x>>y;
			sub[x].push_back(make_pair(i,y));
			v[i].push_back(make_pair(x,y));
		}
		sort(v[i].begin(),v[i].end());
	}
	for(i=1;i<=m;i++)sort(sub[i].begin(),sub[i].end());
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			add(i,j);
		}
	}
	for(i=1;i<=n;i++)get(i);
	for(i=1;i<=Q;i++){
		cin>>x>>y;
		cout<<work(x,y)<<"\n";
	}
}
