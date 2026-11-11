#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
bool vis[1000000];
ll c,n,m,dd,q;
ll a[1000000],d[1000000],dp[1000][1000],gph[1000][1000];
vector<pi> v[1000000],v2[1000];
priority_queue<pi> pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	if(c>=1 && c<=6){
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			ll k,x,y;
			cin>>k;
//			cout<<i<<"abc"<<k<<'\n';
			while(k--){
				cin>>x>>y;
				v[i+m].push_back({y,x});
				v[x].push_back({y,i+m});
			}
		}
		while(q--){
//			cout<<"abc"<<' '<<q<<'\n';
			for(int i=1;i<=m+n;i++){
				vis[i]=0;
				d[i]=5e17;
			}
			while(!pq.empty()){
				pq.pop();
			}
			ll x,y;
			cin>>x>>y;
			d[x]=0;
			pq.push({0,x});
			while(!pq.empty()){
				ll xx=pq.top().second;
				if(vis[xx]){
					continue;
				}
				vis[xx]=1;
				ll sz=v[xx].size();
//				cout<<xx<<"bcd"<<sz<<'\n';
				pq.pop();
				for(int i=0;i<sz;i++){
					if(!vis[v[xx][i].second]){
						if(d[v[xx][i].second]>d[xx]+v[xx][i].first){
							d[v[xx][i].second]=min(d[v[xx][i].second],d[xx]+v[xx][i].first);
//							cout<<xx<<' '<<v[xx][i].second<<' '<<d[v[xx][i].second]<<'\n';
							pq.push({-d[v[xx][i].second],v[xx][i].second});
						}
					}
				}
			}
			cout<<d[y]+a[x]+a[y]<<'\n';
		}
		return 0;
	}
	else{
//		cout<<123<<'\n';
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				gph[i][j]=(i==j) ? 0 : 5e17;
			}
		}
//		cout<<456<<'\n';
		for(int i=1;i<=n;i++){
			ll k;
			cin>>k;
			while(k--){
				ll x,y;
				cin>>x>>y;
				ll sz=v[x].size();
				for(int j=0;j<sz;j++){
					gph[i][v[x][j].second]=gph[v[x][j].second][i]=min(gph[i][v[x][j].second],v[x][j].first+y);
//					v2[i].push_back({v[x][j].first+y,v[x][j].second});
//					v2[v[x][j].second].push_back({v[x][j].first+y,i});
				}
				v[x].push_back({y,i});
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j && gph[i][j]!=5e17){
					v2[i].push_back({gph[i][j],j});
				}
			}
		}
		for(int ii=1;ii<=n;ii++){
			for(int i=1;i<=m;i++){
				vis[i]=0;
				dp[ii][i]=5e17;
			}
			while(!pq.empty()){
				pq.pop();
			}
			dp[ii][ii]=0;
			pq.push({0,ii});
			while(!pq.empty()){
				ll xx=pq.top().second;
				if(vis[xx]){
					continue;
				}
				vis[xx]=1;
				ll sz=v2[xx].size();
//				cout<<xx<<"bcd"<<sz<<'\n';
				pq.pop();
				for(int i=0;i<sz;i++){
					if(!vis[v2[xx][i].second]){
						if(dp[ii][v2[xx][i].second]>dp[ii][xx]+v2[xx][i].first){
							dp[ii][v2[xx][i].second]=min(dp[ii][v2[xx][i].second],dp[ii][xx]+v2[xx][i].first);
//							cout<<xx<<' '<<v[xx][i].second<<' '<<d[v[xx][i].second]<<'\n';
							pq.push({-dp[ii][v2[xx][i].second],v2[xx][i].second});
						}
					}
				}
			}
		}
		while(q--){
			ll ans=1e18;
			ll x,y;
			cin>>x>>y;
			ll sz1=v[x].size(),sz2=v[y].size();
			for(int i=0;i<sz1;i++){
				for(int j=0;j<sz2;j++){
					ans=min(ans,dp[v[x][i].second][v[y][j].second]+v[x][i].first+v[y][j].first);
				}
			}
			cout<<ans+a[x]+a[y]<<'\n';
		}
	}
	return 0;
}

