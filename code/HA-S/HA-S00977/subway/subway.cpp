#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;
int n,m,c,d,p,u1,maxx,v1,u,v,w[1000000],k[1000000],dis[1000000];
vector<pair<int,int> > ju[1000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		maxx=max(maxx,k[i]);
		for(int j=1;j<=k[i];j++){
			cin>>u>>v;
			ju[u].push_back({m+i,v});
			ju[m+i].push_back({u,v});
		}
	}for(int i=1;i<=p;i++){
		for(int j=1;j<=m+n;j++){
			dis[j]=1e9;
		}while(q.size())q.pop();
		int x,y;
		cin>>x>>y;
		dis[x]=0;
		q.push({0,x});
		while(q.size()){//dijstra最短路 预估复杂度 O（q(m+d)n），约五十分 
			int k=q.top().second;
//			cout<<k<<endl;
			q.pop();
			for(int j=0;j<ju[k].size();j++){
				int v1=ju[k][j].first;
				if(dis[v1]>dis[k]+ju[k][j].second){
					dis[v1]=dis[k]+ju[k][j].second;
					q.push({dis[k]+ju[k][j].second,v1});
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
