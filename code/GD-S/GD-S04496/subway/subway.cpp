#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=5e5+500;
int c,n,m,d,p;
ll w[N],dist[M];
bool st[M];
vector<pair<int,ll>> edge[M]; 
ll spfa(int begin,int to){
	memset(st,false,sizeof(st));
	memset(dist,0x3f,sizeof(dist));
	queue<int> q;
	q.push(begin);
	st[begin]=true;
	dist[begin]=0;
	
	while(q.size()){
		int x=q.front();
		q.pop();
		st[x]=false;
		for(auto i:edge[x]){
			int a=i.first;ll b=i.second;
			if(dist[a]>dist[x]+b){
				dist[a]=dist[x]+b;
				if(!st[a]){
					st[a]=true;
					q.push(a);
				}
			}
		}
	}
	
	return dist[to];
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
		cin>>w[i];
		
	for(int i=1;i<=n;i++){
		int t;cin>>t;
		while(t--){
			int x,t;
			cin>>x>>t;
			edge[500+i].push_back({x,t});
			edge[x].push_back({500+i,t});
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+spfa(x,y)<<'\n';
	}
	return 0;
}
