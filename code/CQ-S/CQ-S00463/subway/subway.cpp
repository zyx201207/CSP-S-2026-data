#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int c,n,m,d,q,w[500005],k[505],qq[500005],hh=0,tt=0;
int h[2000005],ne[2000005],e[2000005],f[2000005],idx;
int h2[1000005],ne2[1000005],e2[1000005],f2[1000005],idx2;
long long dis[505][505];
void add(int u,int v,int w){
	e[idx]=v,ne[idx]=h[u],f[idx]=w,h[u]=idx++;
}
void add2(int u,int v,int w){
	e2[idx2]=v,ne2[idx2]=h2[u],f2[idx2]=w,h2[u]=idx2++;
}
vector<pair<int,int> > v[505];
priority_queue<pair<long long,int> > pq;
void bfs(int s){
//	cout<<s<<"sm------------------------"<<endl;
	pq.push({0,s});
	for(int j=1;j<=n;j++){
		dis[s][j]=LONG_LONG_MAX;
	}
	dis[s][s]=0;
	while(!pq.empty()){
		pair<long long,int> tx=pq.top();
		int ww=tx.first,x=tx.second;
//		cout<<-ww<<" "<<x<<"hhh------------------"<<endl; 
		pq.pop();
		for(int i=h2[x];~i;i=ne2[i]){
			int j=e2[i],w=f2[i];
//			cout<<j<<" "<<w<<endl;
			if(dis[s][j]>dis[s][x]+w){
				dis[s][j]=dis[s][x]+w;
				pq.push({-dis[s][j],j});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(h,-1,sizeof(h));
	memset(h2,-1,sizeof(h2));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,b;
			cin>>a>>b;
			v[i].push_back({a,b}); 
			add(a,i+m,b);
		}
	}
//	cout<<"-------------"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=h[v[i][j].first];~k;k=ne[k]){
				int u=e[k]-m;
				if(u!=i){
//					cout<<i<<" "<<u<<" "<<v[i][j].second+f[k]<<endl;
					add2(i,u,v[i][j].second+f[k]);
				}
			}
		}
	}
//	cout<<"gunmu"<<endl;
	for(int i=1;i<=n;i++){
		bfs(i);
	}
//	cout<<"hyw"<<endl;
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=LONG_LONG_MAX;
		for(int i=h[x];~i;i=ne[i]){
			int l1=e[i]-m;
			for(int j=h[y];~j;j=ne[j]){
				int l2=e[j]-m;
				ans=min(ans,1ll*(w[x]+f[i]+dis[l1][l2]+f[j]+w[y]));
			}
		} 
		cout<<ans<<endl;
	} 
	return 0;
}
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
//分来，分来，分来，分来 
