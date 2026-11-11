#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fs first
#define sc second
int c,n,m,d,q;
int a[1005];
set<pair<int,pair<int,int>>> st;
vector<pair<pair<int,int>,int>> v[1005][25];
map<pair<int,pair<int,int>>,int> dis;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1,x;i<=m;i++){
		cin>>x;
		v[i][0].push_back({{i,1},x});
		v[i][1].push_back({{i,0},x});
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=1,z;j<=x;j++){
			cin>>a[j]>>z;
			v[a[j]][i+1].push_back({{a[j],1},z});
			v[a[j]][1].push_back({{a[j],i+1},z});
		}
		for(int j=1;j<=x;j++){
			if(j<x) v[a[j]][i+1].push_back({{a[j+1],i+1},0});
			if(j>1) v[a[j]][i+1].push_back({{a[j-1],i+1},0});
		}
	}
	for(int i=1;i<=m;i++){
		st.insert({0,{i,0}});
		dis[{i,{i,0}}]=0;
		while(!st.empty()){
			auto x=*st.begin();
			auto y=x.sc;
			st.erase(x);
			for(auto ch:v[y.fs][y.sc])
				if((!dis.count({i,ch.fs}))||dis[{i,ch.fs}]>dis[{i,y}]+ch.sc){
					st.erase({dis[{i,ch.fs}],ch.fs});
					dis[{i,ch.fs}]=dis[{i,y}]+ch.sc;
					st.insert({dis[{i,ch.fs}],ch.fs});
				}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[{x,{y,0}}]<<"\n";
	}
	return 0;
}
