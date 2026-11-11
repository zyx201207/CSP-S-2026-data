#include<bits/stdc++.h> 
#define int long long
using namespace std;

const int N=5e5+10;

int dp[1100][1100];

int c,n,m,d,q,w[N];

vector<pair<int,int> > v,e[N];

inline void dij(int x){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(make_pair(0ll,x));
	
	while(!q.empty()){
		pair<int,int> i=q.top();
		q.pop();
		
		for(auto j:e[i.second]){
			if(i.first+j.second<dp[x][j.first]){
				dp[x][j.first] = i.first + j.second;
				q.push(make_pair(dp[x][j.first],j.first));
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	memset(dp,0x3f3f3f3f,sizeof dp);
	
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=1,x;i<=n;i++){
		cin>>x;
		pair<int,int> y;
		v.clear();
		while(x--){
			cin>>y.first>>y.second;
			v.push_back(y);
		}
		for(int j=0;j<v.size();j++){
			for(int k=j+1;k<v.size();k++){
//				cout<<v[j].second+v[k].second<<'\n';
				e[v[j].first].push_back(make_pair(v[k].first,v[j].second+v[k].second));
				e[v[k].first].push_back(make_pair(v[j].first,v[j].second+v[k].second));
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		dij(i);
	}
	
	int u,v;
	
	while(q--){
		cin>>u>>v;
		
		cout<<dp[u][v]+w[u]+w[v]<<'\n';
	}
	
	return 0;
}
