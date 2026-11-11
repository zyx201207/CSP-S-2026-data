#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
//struct node{
//	int u,w;
//	bool operator < (const node& o) const {
//		return o.w<w; 
//	} 
//};
//int dis[N],vis[N];
//void dij(int s,int t){
//	priority_queue<node> pq;
//	for(int i=1;i<=n;i++)
//		dis[i]=1e18;
//	dis[s]=0;
//	pq.push({s,0});
//	while(!pq.empty()){
//		int u=pq.top();
//		pq.pop();
//		if(vis[u])
//			continue;
//		vis[u]=1;
//		for(auto v:G[u]){
//			if(dis[u]+v.se<dis[v.fi]){
//				dis[v.fi]=dis[u]+v.se;
//				pq.push({v.fi,dis[v.fi]});
//			}
//		}
//	} 
//}
int c,n,m,d,q;
int w[500005];
int k[500005];
int val[500005][15],vis[500005][15];
vector<int> G[500005],G2[505],aa[505]; 
struct node{
	int fi,se,res;
};
int ans;
int u,v;
void srh(node x){
	if(x.fi==v){
//		cout<<x.se<<' '<<val[x.fi][x.se]<<endl;
		ans=min(ans,x.res+val[x.fi][x.se]);
		return ;
	} 
	for(int i=1;i<=n;i++){
		if(val[x.fi][i]&&i!=x.se&&!vis[x.fi][i]){
			vis[x.fi][i]=1;
			srh({x.fi,i,x.res+val[x.fi][i]+val[x.fi][x.se]}); 
			vis[x.fi][i]=0;
		}
	}
	for(auto y:G[x.fi]){
//		cout<<y<<endl;
		for(int i=1;i<=n;i++){
			if(val[y][i]&&!vis[y][i]&&i==x.se){
				vis[y][i]=1;
				if(i==x.se){
					srh({y,i,x.res});
				}
				vis[y][i]=0;
//				else{
//					cout<<y<<' '<<i<<' '<<x.res<<' '<<x.fi<<' '<<x.se<<endl;
//					qu.push({y,i,x.res+val[y][i]+val[y][x.se]});
//				}
			}
		}
	}
}
int f[505],viss[505];
void srh(int x,int res){
//	cout<<x<<' '<<res<<endl;
	if(f[x]){
		ans=min(ans,res);
		return;
	}
	if(res>ans)
		return;
	for(auto y:G2[x]){
//		cout<<y<<endl;
		if(!viss[y]){
			viss[y]=1;
			srh(y,res+1); 
			viss[y]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i]; 
	if(9<=c&&c<=15){
		 int vv=0;
		for(int i=1;i<=n;i++){
			cin>>k[i];
			int pre=0;
			for(int j=1;j<=k[i];j++){
				int a,t;
				cin>>a>>t;
				vv=t;
				aa[i].pb(a);
				val[a][i]=t;
				if(pre){
					G[a].pb(pre);
					G[pre].pb(a);
				}
				pre=a;
			}
		}
		for(int i=1;i<=n;i++){
			set<int> st;
//			cout<<" "<<i<<endl;
			for(int j:aa[i]){
//				cout<<j<<endl;
				for(int ii=1;ii<=n;ii++)
					if(val[j][ii]&&ii!=i){
						st.insert(ii);
//						cout<<"  "<<ii<<endl;
					}
			}
			for(auto j:st)
				G2[i].pb(j),G2[j].pb(i); 
		}
		while(q--){
			int u,v;
			cin>>u>>v;
			queue<pii> qu;
			for(int i=1;i<=n;i++)
				viss[i]=0;
			ans=1e9;
			for(int i=1;i<=n;i++){
				if(val[v][i]){
					f[i]=1;
				}
				else
					f[i]=0;
			}
			for(int i=1;i<=n;i++){
				if(val[u][i]){
					viss[i]=1;
					qu.push({i,0});
				}
			}
			while(!qu.empty()){
				int x=qu.front().fi,res=qu.front().se;
				qu.pop();
//				cout<<x<<' '<<f[x]<<endl;
				if(f[x]){
					ans=min(ans,res);
					continue;
				}
				if(res>ans)
					continue;
				for(auto y:G2[x]){
			//		cout<<y<<endl;
					if(!viss[y]){
						viss[y]=1;
						qu.push({y,res+1}); 
//						viss[y]=0;
					}
				}
			}
//			cout<<ans<<endl;
			cout<<(ans+1)*2*vv+w[u]+w[v]<<endl;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>k[i];
			int pre=0;
			for(int j=1;j<=k[i];j++){
				int a,t;
				cin>>a>>t;
				val[a][i]=t;
				if(pre){
					G[a].pb(pre);
					G[pre].pb(a);
				}
				pre=a;
//				for(auto u:v[a]){
//					off++;
//					G[off].pb({}) 
//				}
			}
		}
		while(q--){
			for(int i=1;i<=m;i++)
				for(int j=1;j<=n;j++)
					vis[i][j]=0;
			cin>>u>>v;
			ans=1e9;
			queue<node> qu;
			for(int i=1;i<=n;i++)	
				if(val[u][i])
					srh({u,i,val[u][i]}),vis[u][i]=1;
//			while(!qu.empty()){
//				auto x=qu.front();
//				cout<<x.fi<<' '<<x.se<<' '<<x.res<<endl;
//				qu.pop();
//				
//			}
			cout<<ans+w[u]+w[v]<<endl;
		}
	}
	return 0;
} 
/*
0 5 8 20 2
8 3 6 1 7 2 9 2
3 1 4 2 4 5 4
3 2 4 3 4 7 4
4 3 4 5 4 4 4 6 4
4 7 4 4 4 8 4 6 4
3 1 4 4 4 3 4
1 8
2 4
*/
