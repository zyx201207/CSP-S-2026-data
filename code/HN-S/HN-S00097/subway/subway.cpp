#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int> >  tree[50005];
int c,n,m,d,q;
int cost[50005];
bool vis[50005];
vector<pair<int,int> > arrive[505];
long long dist[50005];

void dj(int begin){
	vector<pair<int,int> > q;
	for(int i = 1;i <= m;i++) dist[i] = 0x3f3f3f3f;
	for(int i= 1;i <= m;i++) dist[i] = false;
	
	q.push_back({0,begin});
	dist[begin] = 0;
	while(!q.empty()){
		sort(q.begin(),q.end());
		pair<int,int >  head = q.back();
		vis[head.second] = true;
		q.pop_back();
		int ts = tree[head.second].size();
		for(int i = 0;i < ts;i++){
			int td = 0;
			if(vis[tree[head.second][i].second]) continue;
			td = head.first + tree[head.second][i].first;
			if(td < dist[tree[head.second][i].second]){
				dist[tree[head.second][i].second] = td;
				q.push_back({td,tree[head.second][i].second});
			}
		}
		
	}
	
	
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	pair<int,int > vessal;
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> cost[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int ii= 1;ii <= k;ii++){
			int ta,tt;
			cin >> ta >> tt;
			
			arrive[i].push_back({ta,tt});
		} 
		for(int ii = 1;ii <=k;ii++){
			tree[arrive[i][ii].first].push_back({arrive[i][ii].second*2,arrive[i][ii].first});
			
		}
		
		
	}
	for(int i = 1;i <= q;i++){
		int ss,ee;
		cin >> ss >> ee;
		dj(ss);
		cout << dist[ee] + cost[ss] + cost[ee] << endl;
	}
	return 0;
	
	
	  
	
	
	
}
