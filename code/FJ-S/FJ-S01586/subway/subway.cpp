#include<bits/stdc++.h>
using namespace std;

#define N 501
#define M 500001
#define INF 0x7fffffffffffffffLL
#define ll long long

struct Line{
	//to is station,val is time
	int to,val;
};

//the station infomation in which lineroad
vector<Line>line[N];
//key is lineroad's id,val is time
map<int,int>l[M];
//time
int w[M];
int c,n,m,d,q;

ll dijkstra(int,int);

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
//	CFS g(n);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
//		ans+=k-1;
		line[i].assign(k+1,{0,0});
		for(int j=1;j<=k;j++){
			cin>>line[i][j].to>>line[i][j].val;
			int to=line[i][j].to,val=line[i][j].val;
//			cin>>to>>val;
			l[to][i]=val;
		}
	}
	
//	CFS g(n,ans);
//	for(int i=1;i<=n;i++){
//		for(auto x:l[i])
//			g.add(i,l[i].second,l[i].first);
//	}

	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y)<<'\n';
//		cout<<g.dijkstra(x,y)<<'\n';
	}
	return 0;
}

inline ll dijkstra(int st,int tar){
	vector<ll>dis(n+1,INF);
	dis[st]=w[st];
	vector<pair<ll,pair<int,int> > >t;
	t.reserve(n);
	priority_queue<pair<ll,pair<int,int> >,
		vector<pair<ll,pair<int,int> > >,
		greater<pair<ll,pair<int,int> > >
	>pq(greater<pair<ll,pair<int,int> > >(),std::move(t));
	for(auto x:l[st])
		pq.push({dis[st],{st,x.second}});
	while(!pq.empty()){
		pair<ll,pair<int,int> >now=pq.top();
		pq.pop();
		ll&c=now.first;
		int&u=now.second.first,&ls=now.second.second;
		if(c>dis[u])
			continue;
//		cerr<<u<<':'<<c<<'\n';
		if(u==tar)
			return dis[u]+w[tar];
		for(auto x:l[u]){
			if(ls==x.first){
				for(int i=1;i<line[x.first].size();i++)
					if(dis[u]!=INF&&dis[u]<dis[i]){
						dis[i]=dis[u];
						pq.push({dis[i],{i,x.first}});
//						cerr<<"to "<<i<<" with "<<dis[i]<<'\n';
					}
			}
			else{
				for(int i=1;i<line[x.first].size();i++)
					if(dis[u]!=INF&&dis[u]+l[u][x.first]+l[u][ls]<dis[i]){
						dis[i]=dis[u];
						pq.push({dis[i],{i,x.first}});
//						cerr<<"to "<<i<<" with "<<dis[i]<<'\n';
					}
			}
		}
//		for(int i=head[u];i!=-1;i=edge[i].next){
//			int&v=edge[i].to,&ls=edge[i].ls;
//			if(dis[u]==INF)
//				break;
//			if(ls==edge[v].ls&&dis[u]<dis[v]){
//				dis[v]=dis[u];
//				pq.push({dis[v],{v,ls}});
//			}
//			if(ls!=edge[v].ls&&dis[u]+l[u][ls]+l[u][edge[v].ls]<dis[v]){
//				dis[v]=dis[u];
//				pq.push({dis[v],{v,ls}});
//			}
//		}
	}
	return dis[tar]+w[tar];
}
//class CFS{
//	typedef long long ll;
////	typedef pair<ll,int> pli;
//	
//	private:
//		struct Edge{
//			int to,next,ls;
//		};
//		vector<Edge>edge;
//		vector<int>head;
//		int n,tot;
//		
//		static ll const INF=0x7fffffffffffffffll;
//	
//	public:
//		CFS(int _n):n(_n),tot(0){
//			head.assign(n+1,-1);
//			edge.push_back({0,-1,0});
//		}
//		
//		CFS&add(int u,int v,int ls){
//			edge.push_back({v,head[u],ls});
////			edge[]={v,head[u],ls};
//			head[u]=tot++;
//			return*this;
//		}
//		
//		ll dijkstra(int st,int tar){
//			vector<ll>dis(n+1,INF);
//			dis[st]=w[st];
//			vector<pair<ll,pair<int,int> > >t;
//			t.reserve(n);
//			priority_queue<pair<ll,pair<int,int> >,
//				vector<pair<ll,pair<int,int> > >,
//				greater<pair<ll,pair<int,int> > >
//			>pq(greater<pair<ll,pair<int,int> > >(),std::move(t));
//			for(auto x:l[st])
//				pq.push({dis[st],{st,x.second}});
//			while(!pq.empty()){
//				pair<ll,pair<int,int> >now=pq.top();
//				pq.pop();
//				ll&c=now.first;
//				int&u=now.second.first;//&ls=now.second.second;
//				if(c>dis[u])
//					continue;
//				if(u==tar)
//					return dis[u]+w[tar];
//				for(int i=head[u];i!=-1;i=edge[i].next){
//					int&v=edge[i].to,&ls=edge[i].ls;
//					if(dis[u]==INF)
//						break;
//					if(ls==edge[v].ls&&dis[u]<dis[v]){
//						dis[v]=dis[u];
//						pq.push({dis[v],{v,ls}});
//					}
//					if(ls!=edge[v].ls&&dis[u]+l[u][ls]+l[u][edge[v].ls]<dis[v]){
//						dis[v]=dis[u];
//						pq.push({dis[v],{v,ls}});
//					}
//				}
//			}
//			return dis[tar]+w[tar];
//		}
//};
