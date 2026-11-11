#include<bits/stdc++.h>
#define int long long
using namespace std;
using Node=pair<int,int>;
int c,n,m,d,q;
int w[10000010],cnt[10000010];
struct Edge{
	int to,weight;
};
vector<Edge>g[10000010];
int timea[10000010],dist[10000010],tot;
int solve(int x,int y){
	priority_queue<Node,vector<Node>,greater<Node>>q;
	fill(dist+1,dist+tot+1,1e18);
	for(int i=0;i<=cnt[x];i++)
		if(timea[x+i*m])
		{
			q.push({timea[x+i*m],x+i*m});
			dist[x+i*m]=timea[x+i*m];
		}
	while(!q.empty()){
		int ud=q.top().first,u=q.top().second;
		q.pop();
		if(dist[u]<ud)continue;
		for(auto i:g[u]){
			int v=i.to,wv=i.weight;
			if(ud+wv<dist[v]){
				dist[v]=ud+wv;
				q.push({dist[v],v});
			}
		}
	}
	int res=1e18;
	for(int i=0;i<=cnt[y];i++)
		if(timea[y+i*m])
			res=min(res,dist[i*m+y]+timea[i*m+y]);
	return res;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		cnt[i]=-1;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int cura=0,curt;
		while(k--){
			int a,t;
			cin>>a>>t;
			cnt[a]++;
			tot=max(tot,a+cnt[a]*m);
			if(!cura)
				 cura=a+cnt[a]*m,curt=t;
			else
			{
				g[a+cnt[a]*m].push_back({cura,0});
				g[cura].push_back({a+cnt[a]*m,0});
				cura=a+cnt[a]*m,curt=t;
			}
			timea[a+cnt[a]*m]=t;
			for(int j=0;j<cnt[a];j++)
				if(timea[j*m+a]){
					g[j*m+a].push_back({cnt[a]*m+a,t+timea[j*m+a]});
					g[cnt[a]*m+a].push_back({j*m+a,t+timea[j*m+a]});	
				}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+solve(x,y)<<'\n';
	}
	return 0;
}

