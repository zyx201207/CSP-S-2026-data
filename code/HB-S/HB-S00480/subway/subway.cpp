#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[510000],dis[501000];
map<pair<int,int>,int> ans;bool vis[510000];
vector<pair<int,int> > l[600];
vector<pair<int,int> > b[510000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		for(int j=1;j<=x;j++){
			int y,z;cin>>y>>z;
			l[i].push_back({y,z});
			b[y].push_back({i,z});
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		if(vis[s]==1){
			cout<<ans[{s,t}]+w[s]+w[t]<<endl;continue;
		}else if(vis[t]==1){
			cout<<ans[{t,s}]+w[s]+w[t]<<endl;continue;
		}
		memset(dis,0x7f,sizeof(dis));
		priority_queue<pair<int,int> > q;
		q.push({0,s});
		dis[s]=0;
		while(!q.empty()){
			int ds=-1*q.top().first,id=q.top().second;q.pop();
			//cout<<id<<" ";
			for(auto x:b[id]){
				for(auto i:l[x.first]){
					if(dis[i.first]>ds+i.second+x.second){
						dis[i.first]=ds+i.second+x.second;
						q.push({-1*dis[i.first],i.first});
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			//if(dis[i]==0x7f7f7f7f) cout<<-1<<' ';
			//else cout<<dis[i]<<' ';
			ans[{s,i}]=dis[i];
		}
		vis[s]=1;
		
		cout<<dis[t]+w[s]+w[t]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/
