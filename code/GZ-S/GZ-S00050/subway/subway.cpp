//GZ-S00050，阮辰允，贵阳市白云区华师一学校 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,cnt,dis[2000001];
vector<vector<pair<int,int> > > g;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    cnt=2*m;
    g.resize(2*m+1); 
    for(int i=1;i<=m;i++){
    	int w;
    	cin>>w;
    	g[m+i].push_back({i,w});
    	g[i].push_back({m+i,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int scnt=cnt;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g.push_back({});
			g[++cnt].push_back({a,t});
			g[a].push_back({cnt,t});
			if(cnt-scnt>1){
				g[cnt].push_back({cnt-1,0});
				g[cnt-1].push_back({cnt,0});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		for(int j=1;j<=cnt;j++){
			dis[j]=1e18;
		}
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
		q.push({0,s+m});
		while(q.size()){
			int u=q.top().second,d=q.top().first;
			q.pop();
			if(dis[u]>d){
				dis[u]=d;
				for(auto vw:g[u]){
					int v=vw.first,w=vw.second;
					q.push({dis[u]+w,v});
				}
			}
		}
		cout<<dis[t+m]<<'\n';
	}
    return 0;
}
