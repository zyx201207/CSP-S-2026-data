#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w,k,xr,yr,a[555555];
bool vis[555555];
struct str{
	long long to,w;
}road;
vector<str> ve[555555];
pair<long long,long long> u;
int dij(int r){
	priority_queue<pair<long long,long long>> qu;
	qu.push(make_pair(0,r));
	while(!qu.empty()){
		u=qu.top();
		qu.pop();
		if(vis[u.second]!=0) continue;
		vis[u.second]=1;
		if(u.second==yr) return u.first;
		long long lenth=ve[u.second].size();
		for(int i=0;i<lenth;i++){
			int v=ve[u.second][i].to;
			if(vis[v]!=0) continue;
			qu.push(make_pair(u.first+ve[u.second][i].w,v));
		}
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>w>>road.w;
			road.to=i+m;
			ve[w].push_back(road);
			road.to=w;
			ve[i+m].push_back(road);
		}
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		cin>>xr>>yr;
		cout<<dij(xr)+a[xr]+a[yr]<<endl;
	}
	return 0;
}
