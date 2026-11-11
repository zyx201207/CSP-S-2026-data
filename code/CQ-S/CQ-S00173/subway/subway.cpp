#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qs,u,w[501][500001],o[500001],k,dis[500001],x,y,ans;
struct lob{
	int d,w,l;
};
struct cmp{
	bool operator()(lob a,lob b){
		return a.w>b.w;
	}
};
vector<int> g[501],f[500001];
priority_queue<lob,vector<lob>,cmp> q;
void dij(int d,int l){
	if(w[l][d]==-1) return ;
	dis[d]=w[l][d];
	q.push({d,w[l][d],l});
	while(!q.empty()){
		lob t=q.top();
		q.pop();
		for(int i=0;i<g[t.l].size();i++){
			int lo=g[t.l][i];
			if(dis[lo]<=t.w+w[t.l][lo]) continue;
			dis[lo]=t.w+w[t.l][lo];
			q.push({lo,t.w+w[t.l][lo],t.l});
		}
		for(int i=0;i<f[t.d].size();i++){
			int fo=f[t.d][i];
			for(int i=0;i<g[fo].size();i++){
				int lo=g[fo][i];
				if(fo==t.l){
					if(dis[lo]<=t.w+w[fo][lo]) continue;
					dis[lo]=t.w+w[fo][lo];
					q.push({lo,t.w+w[fo][lo],fo});
				}else{
					if(dis[lo]<=t.w+w[fo][lo]+w[fo][t.d]) continue;
					dis[lo]=t.w+w[fo][lo]+w[fo][t.d];
					q.push({lo,t.w+w[fo][lo]+w[fo][t.d],fo});
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qs;
	for(int i=1;i<=m;i++) cin>>o[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) w[i][j]=-1;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>w[i][u];
			g[i].push_back(u);
			f[u].push_back(i);
		}
	}
	for(int i=1;i<=qs;i++){
		cin>>x>>y;
		ans=INT_MAX;
		for(int j=1;j<=n;j++){
			for(int h=1;h<=m;h++) dis[h]=INT_MAX;
			dij(x,j);
			ans=min(ans,dis[y]+o[x]+o[y]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
