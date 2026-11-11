#include<bits/stdc++.h>
using namespace std;
int n,m,d;
struct ln{
	int to,w;
};
vector<ln> q[200000];
int k;
int a[200000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	cin>>n>>m>>d>>k;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
		
	}
	for(int i = 1;i <= m;i ++){
		int k;
		cin>>k;
		int cnt = 0;
		for(int j = 1;j <= k;j ++){
			int a,b;
			cin>>a>>b;
			q[n+(++cnt)].push_back({a,b});
			q[a].push_back({n+(++cnt)},b);
		}
	}
	int dist[200000];
	fill(dist + 1,dist+n+1,0xcfcfccf); 
	for(int i = 1;i <= d;i ++){
		int s,t;
		cin>>s>>t;
		priority_queue<pair<int,int>,vector<int,int>,greater<int> > h;
		h.push_back({0,s});
		dis[s] = 0;
		while(h.empty()){
			auto pre = h.front();
			h.pop();
			if(dis[pre.second] < pre.first) continue;
			for(int i = 0;i < q[pre.second].size();i ++){
				h.push_back({q[pre.second][i].w + pre.first,q[pre.second][i].to})
			}
		}
		cout<<dist[t]<<'\n';
	}
}
