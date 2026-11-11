#include<bits/stdc++.h>
using namespace std;

#define int long long 
const int N=5e5+2;
vector<int> graph[N],tim[N],idx[N],line[N];
int w[N];
void add_edge(int u,int v){
	graph[u].push_back(v);
	graph[v].push_back(u);	
}

const int INF=1e18;
bool vis[N];
int dfs(int v,int t){
	if(v==t||vis[v]){
		return 0;
	}
	vis[v]=true;
	int dist=0;
	for(int u:graph[v]){
		if(vis[u]){
			continue;
		}
		for(int i:idx[u]){
			if(binary_search(idx[v].begin(),idx[v].end(),i)){
				
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int lst=-1;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			idx[a].push_back(i);
			line[i].push_back(a);
			if(lst!=-1){
				add_edge(lst,a);
			}
			tim[i].push_back(t);
			lst=a;
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		srand(time(0));
		cout<<rand()%INF+1<<'\n';
	}
	return 0;
}

