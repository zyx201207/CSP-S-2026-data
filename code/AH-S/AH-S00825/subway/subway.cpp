#include<bits/stdc++.h>
using namespace std;
using Pa=pair<long long,int>;
const int N=5e5+5;
int c,n,m,d,q,w[N];
long long dis[N];
bool vis[N];
vector<Pa>g[505];
priority_queue<Pa,vector<Pa>,greater<Pa>>qp;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
    	int k,fa,ft;
    	cin>>k;
    	for(int j=0;j<k;j++){
    		int a,t;
    		cin>>a>>t;
    		if(j==0){
    			fa=a,ft=t;
    			continue;
			}
	    	g[a].push_back({(long long)(t+ft),fa});
	    	g[fa].push_back({(long long)(t+ft),a});
	    }
	}
	for(int r=0,xr,yr;r<q;r++){
		cin>>xr>>yr;
		for(int i=1;i<=m;i++)
			vis[i]=0,dis[i]=1e18;
		while(!qp.empty()) qp.pop();
		dis[xr]=0;
		qp.push({(long long)0,xr});
		while(!qp.empty()){
			int u=qp.top().second;
			qp.pop();
			if(vis[u]==1) continue;
			vis[u]=1;
			for(int i=0,sz=g[u].size();i<sz;i++){
				long long fv=g[u][i].first;
				int idx=g[u][i].second;
				if(dis[idx]>dis[u]+fv){
					dis[idx]=dis[u]+fv;
					qp.push({dis[idx],idx});
				}
			}
		}
		cout<<(dis[yr]+w[xr]+w[yr])<<'\n';
	}
	return 0;
}
