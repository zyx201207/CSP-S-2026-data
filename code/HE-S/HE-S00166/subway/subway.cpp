#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505 ,M=5e5+5;
int c,n,m,d,q,x,y;
ll w[M],k[N],ans;
vector<ll>a[N],t[N];
map<int,vector<ll> >mp;
bool vis[M];
struct sta {
	vector<pair<int,int> >line;//车站 ，线路
	map<int,int> zt;
} e[M];
void bfs(int xian) {
//	priority_queue <pair<ll,pair<int,int> > ,vector<pair<ll,pair<int,int> > > ,greater<pair<ll,pair<int,int> > > >qu;//现车站，现距离，现线路
	stack<pair<ll,pair<int,int> > >qu;
	vis[x]=true;
	qu.push(make_pair(0,make_pair(x,xian)));
	while(!qu.empty()) {
		ll dis=qu.top().first;
		int nost=qu.top().second.first;
		int noln=qu.top().second.second;
		qu.pop();
//		cout << nost<<" "<<dis<<" "<<noln<<endl;
		if(nost==y) {
			ll nans=dis+w[x]+w[y]+e[x].zt[xian];
			nans+=e[y].zt[noln];
			ans=min(nans,ans);
			continue;
		}

		for(int i=0; i<e[nost].line.size(); i++) {
			pair<int,int> nest=e[nost].line[i];
			if(!vis[nest.first]) {
				vis[nest.first]=true;
				if(nest.second==noln) {
					qu.push(make_pair(dis,make_pair(nest.first,noln)));
				} else {
					ll sum=0;
					sum+=e[nost].zt[noln];
					sum+=e[nost].zt[nest.second];
					qu.push(make_pair(dis+sum,make_pair(nest.first,nest.second)));
				}
			}
		}
		vis[x]=false;
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		a[i].resize(k[i]+5),t[i].resize(k[i]+5);
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]].push_back(i);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k[i]; j++) {
			e[a[i][j]].zt[i]=t[i][j];
			if(a[i][j-1]) {
				e[a[i][j]].line.push_back(make_pair(a[i][j-1],i ));
			}
			if(a[i][j+1]) {
				e[a[i][j]].line.push_back(make_pair(a[i][j+1],i));
			}
		}
	}
//	for(int i=1; i<=m; i++) {
//		for(int l=0; l<e[i].line.size(); l++) {
//			cout << e[i].line[l].first<<" "<<e[i].line[l].second<<endl;
//		}
//		cout <<endl;
//			for(int l=0;l<mp[a[i][j]].zt.size;l++){
//				cout <<
//			}
//	}
	while(q--) {
		cin>>x>>y;
		ans=INT_MAX;
		for(int i=0; i<mp[x].size(); i++) {
			memset(vis,0,sizeof(vis));
			bfs(mp[x][i]);
		}
		cout <<ans<<endl;
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
