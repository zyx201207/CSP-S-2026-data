#include<bits/stdc++.h>
using namespace std;
struct node{
	int i,v;
};
int c,n,m,D,Q;
int w[505],k[505],t[505][100010];
vector<node>a[500010];
vector<int>d[500010];
vector<int>ls;
bool isd[500010],vis[500010];
bool f[25][505];
map<int,int>mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int last=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			d[x].push_back(i);
			if(d[x].size()>1){
				isd[x]=1;
				ls.push_back(x);
			}
			t[i][x]=y;
			if(last==0){
				last=x;
				continue;
			}
			else{
				node ff;
				ff.i=i;ff.v=last;
				a[x].push_back(ff);
				ff.v=x;
				a[last].push_back(ff);
				last=x;
			}
		}
	}
	int id=1;
	for(auto x:ls){
		mp[x]=id;
		id++;
	}
	while(Q--){
		int st,en;
		long long ans=1;
		cin>>st>>en;
		priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>> >,greater<pair<long long,pair<int,int>> > >q;
		for(auto x:d[st]){
			q.push({0,{1,x}});
		}
		while(!q.empty()){
			long long val=q.top().first, u=q.top().second.first, l=q.top().second.second;

			q.pop();
			if(u==en){
				ans=min(ans,val+w[en]);
				continue;
			}
			if(isd[u]&&f[mp[u]][l]){
				continue;
			}
			if(!isd[u]&&vis[u])continue;
			if(isd[u]&&!f[mp[u]][l]){
				f[mp[u]][l]=1;
			}
			if(!isd[u]&&!vis[u]){
				vis[u]=1;
			}
			for(auto v:a[u]){
				if(isd[v.i]){
					for(auto y:d[v.i]){
						if(y==l)q.push({val,{v.i,l}});
						q.push({val+t[l][v.i]+t[y][v.i],{v.i,y}});
					}
				}
				else q.push({val,{v.i,l}});
			}
		}
		cout<<ans<<endl;
	}
}

