#include<bits/stdc++.h>
using namespace std;
const int N=5e5+505;
int c,n,m,d,q;
int w[N],dis[N];
struct Node{
	int fr,to,ti;
	
};
vector<Node>g[N];
//priority_queue<int,vector<Node>,greater<int> >pq;
queue<Node >aq; 
void dij(int x,int y){
	int ans=0;
	for(int i=1;i<=n+m;i++){
		dis[i]=INT_MAX;
	}
	dis[x]=0;
	for(Node i:g[x]){
		aq.push(i);
	}
	while(!aq.empty()){
		Node xa=aq.front();
		aq.pop();
		dis[xa.to ]=min(dis[xa.fr ]+xa.ti,dis[xa.to]);
		for(Node i:g[xa.to ]){
			
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int id,ti;
			cin>>id>>ti;
			g[i+m].push_back({i+m,id,ti});
			g[id].push_back({id,i+m,ti});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x,y);
	}
	return 0;
} 
