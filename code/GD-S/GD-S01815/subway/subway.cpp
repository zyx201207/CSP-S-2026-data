#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qu,p[500005],dis[501005],v[501005];
vector<pair<int,int>>a[501005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void dij(int s){
	q.push({0,s});
	for(int i=1;i<=m+n;i++){
		dis[i]=INT_MAX;
		v[i]=0;
	}
	dis[s]=0;
	while(!q.empty()){
		int k=q.top().second;
		q.pop();
		if(v[k]==1){
			continue;
		}
		v[k]=1;
		for(int i=0;i<a[k].size();i++){
			if(dis[a[k][i].first]>dis[k]+a[k][i].second){
				dis[a[k][i].first]=dis[k]+a[k][i].second;
				q.push({dis[a[k][i].first],a[k][i].first}) ;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[m+i].push_back({x,y});
			a[x].push_back({m+i,y});
		}
	}
	for(int i=1;i<=qu;i++){
		int s,t;
		cin>>s>>t;
		dij(s);
		cout<<dis[t]+p[s]+p[t]<<'\n';
	}
	return 0;
}
