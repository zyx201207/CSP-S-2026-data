#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > g[5000010];
vector<pair<int,int> > tt[500010];
int dd[5000010];
int a[500010];
int c,n,m,ghjytd,e;
int d(int s,int en){
	int cc=INT_MAX;
	priority_queue<pair<int,int> > q;
	q.push({s,0});
	dd[s]=0;
	while(!q.empty()){
		int h=0-q.top().second;
		int u=q.top().first;
		q.pop();
		if(h>dd[u]) continue;
		dd[u]=h;
		for(int p=0;p<g[u].size();p++){
			int v=g[u][p].first;
			int w=g[u][p].second;
			if(w+h<dd[v]){
				dd[v]=w+h;
				if(v%m==en){
					int uu=dd[v];
					for(int z=0;z<tt[en].size();z++){
						int oo=tt[en][z].first;
						oo=en+(oo-1)*m;
						int zz=tt[en][z].second;
						if(oo==v){
							cc=min(cc,uu+zz);
						}
					}
				}
				q.push({v,0-dd[v]});
			}
		}
	}
	return cc;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>ghjytd>>e;
	memset(dd,0x7f,sizeof(dd));
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int x,y;cin>>x>>y;int ww=x;
		for(int z=0;z<tt[x].size();z++){
			int ii=tt[x][z].first;
			int yy=tt[x][z].second;
			g[x+(i-1)*m].push_back({x+(ii-1)*m,y+yy});
		    g[x+(ii-1)*m].push_back({x+(i-1)*m,y+yy});
		}
		tt[x].push_back({i,y});
		for(int j=2;j<=k;j++){
			cin>>x>>y;
			g[ww+(i-1)*m].push_back({x+(i-1)*m,0});
			g[x+(i-1)*m].push_back({ww+(i-1)*m,0});
			for(int z=0;z<tt[x].size();z++){
				int ii=tt[x][z].first;
				int yy=tt[x][z].second;
				g[x+(i-1)*m].push_back({x+(ii-1)*m,y+yy});
		        g[x+(ii-1)*m].push_back({x+(i-1)*m,y+yy});
			}
			ww=x;
			tt[x].push_back({i,y});
		}
	}
	for(int i=1;i<=e;i++){
		int l,r;cin>>l>>r;
		int sum=INT_MAX;
		memset(dd,0x7f,sizeof(dd));
		for(int j=0;j<tt[l].size();j++){
			int gg=tt[l][j].first;
			gg=l+(gg-1)*m;
			int xx=tt[l][j].second;
			sum=min(sum,d(gg,r)+xx);
		}
		cout<<sum+a[l]+a[r]<<endl;
	}
	return 0;
}
