//感觉自己比hardme还糖 
//B的特殊性质好难 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[505],a[505][20005],Max;
int t[505][20005],cnt[500005],vis[500005],ti[500005][23],tt[5][500005];
long long dis[500005],w[1000005];
int be1[500005],be2[500005];
vector<pair<int,int> > g[200005];
struct query{
	int x,y,ans,id;
}qq[100005];
bool cmp(query s1,query s2){
	return s1.x<s2.x;
}
bool cmp11(query s1,query s2){
	return s1.id<s2.id;
}
long long dijkstra(int x,int y){
	for(int i=1;i<=Max;i++){
		dis[i]=1e18;
	}
	dis[x]=0;
	priority_queue<pair<long long,int> ,vector<pair<long long,int> >,greater<pair<long long,int> > > Q;
	Q.push({0,x});
	while(!Q.empty()){
		int u=Q.top().second;
		Q.pop();
		vis[u]=0;
		for(auto it:g[u]){
			int v=it.first,w=it.second;
//			cout<<u<<' '<<v<<' '<<w<<'\n';
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]) Q.push({dis[v],v});
				vis[v]=1;
			}
		}
	}
	return dis[y];
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		cnt[i]=-1;
	}	
	if(c<=6&&c!=0){
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
				cnt[a[i][j]]++;
				ti[a[i][j]][cnt[a[i][j]]]=t[i][j];
			}
			for(int j=1;j<=k[i];j++){
				for(int l=1;l<=k[i];l++){
					if(j==l) continue;
					g[cnt[a[i][j]]*m+a[i][j]].push_back({cnt[a[i][l]]*m+a[i][l],0});
					Max=max({Max,cnt[a[i][j]]*m+a[i][j],cnt[a[i][l]]*m+a[i][l]});
				}
			}
		}
		for(int i=1;i<=m;i++){
			cnt[i]++;
			for(int j=0;j<=cnt[i];j++){
				for(int l=0;l<=cnt[i];l++){
					if(j==l) continue;
	//				cout<<i+m*j<<' '<<i+m*l<<' '<<ti[i][j]+ti[i][l]<<'\n'; 
					g[i+m*j].push_back({i+m*l,ti[i][j]+ti[i][l]});
					Max=max({Max,i+m*j,i+m*l});
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<dijkstra(x+cnt[x]*m,y+cnt[y]*m)+w[x]+w[y]<<'\n';
		}
	}else if(c<=11&&c!=0){
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j]>>t[i][j];
			}
			if(k[i]==2){
				g[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
				g[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
				Max=max(Max,a[i][1]+a[i][2]);
			}
		}
		for(int i=1;i<=q;i++){
//			int x,y;
			cin>>qq[i].x>>qq[i].y;
			qq[i].id=i;
		}
		sort(qq+1,qq+1+q,cmp);
		int l=1;
		while(l<=q){
			int r=l+1;
			while(r<=q){
				if(qq[l].x!=qq[r].x) break;
				r++;
			}
			dijkstra(qq[l].x,0);
			for(int i=l;i<r;i++){
				qq[i].ans=dis[qq[i].y]+w[qq[i].x]+w[qq[i].y];
			}
			l=r;
		}
		sort(qq+1,qq+1+q,cmp11);
		for(int i=1;i<=q;i++){
			cout<<qq[i].ans<<'\n';
		}
	}else if(n<=19&&c!=0){
		Max=789113;
		cout<<"FuckCCF";
	}else if(n<=21){
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1,a,t;j<=k[i];j++){
				cin>>a>>t;
				tt[i][a]=t;
				if(i==1) be1[a]=1;
				else be2[a]=1;
			}
		}
		int zzr=1e9;
		for(int i=1;i<=m;i++){
			if(be1[i]&&be2[i]){
				zzr=min(zzr,tt[1][i]+tt[2][i]);
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			long long ans=1e18;
			if(be1[x]&&be1[y]){
				ans=min(ans,w[x]+w[y]+tt[1][x]+tt[1][y]);
			}
			if(be2[x]&&be2[y]){
				ans=min(ans,w[x]+w[y]+tt[2][x]+tt[2][y]);
			}
			if(be1[x]&&be2[y]){
				ans=min(ans,w[x]+w[y]+tt[1][x]+tt[2][y]+zzr);
			}
			if(be2[x]&&be1[y]){
				ans=min(ans,w[x]+w[y]+tt[2][x]+tt[1][y]+zzr);
			}
			cout<<ans<<'\n';
		}
	}
}
//橙蓝蓝紫 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--) solve();
	return 0;
}
