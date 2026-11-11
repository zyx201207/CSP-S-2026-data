#include<bits/stdc++.h>
#define int long long
using namespace std;
int T=1;
void init(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
int c,n,m,d,q,ans,x,y;
int w[500001],k[501],a[501][21],t[501][21],bj[500001];
vector<pair<int,int> >v[500001];
struct az{
	int zt,sz,xl,sy;
};
queue<az>p;
void doit(){
	for(int i=1;i<=m;i++){
		bj[i]=1e18;
	}
	bj[x]=0;
	for(int i=0;i<v[x].size();i++){
		p.push({x,w[x]+v[x][i].second,v[x][i].first,1});
	}
	while(!p.empty()){
		az te=p.front();
		p.pop();
		if(te.sy){
			for(int i=1;i<=k[te.xl];i++){
				if(a[te.xl][i]==y){
					ans=min(ans,te.sz+w[y]+v[y][te.xl].second);
					break;
				}
				if(bj[a[te.xl][i]]<=te.sz){
					continue;
				}
				bj[a[te.xl][i]]=te.sz;
				p.push({a[te.xl][i],te.sz,te.xl,0});
			}
		}
		else{
			for(int i=0;i<v[te.zt].size();i++){
				int nxl=v[te.zt][i].first;
				if(nxl==te.xl){
					continue;
				}
				te.sz+=t[te.xl][te.zt]+t[nxl][te.zt];
				p.push({te.zt,te.sz,nxl,1});
			}
		} 
	}
	cout<<ans<<'\n';
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back({i,t[i][j]});
		}
	}
	while(q--){
		cin>>x>>y;
		ans=1e18;
		doit();
	}
	return;
}
signed main(){
	init();
	while(T--){
		solve();
	}
	return 0;
}
