#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,long long>
#define pb push_back
const int maxn=1e6+5,midn=105;
int c,t,n,k;
vector<int>to[maxn];
int f[midn][midn][midn][3],tmp[midn][midn][midn][3];
void dp1(int u,int fa){
	for(int i=k;i>=0;i--)
		for(int j=n;j>=0;j--)
			for(int l=2;l>=0;l--)
				f[u][i][j][l]=0;
	for(int v:to[u]){
		if(v==fa)continue;
		dp1(v,u);
		for(int i=k;i>=0;i--){
			for(int j=n;j>=0;j--){
				for(int l=2;l>=0;l--){
					tmp[u][i][j][l]=1e9;
					if(j-1>=0)tmp[u][i][j][l]=min(tmp[u][i][j][l],max(f[v][i][j-1][l],j));
					//不建 
					if(i-1>=0&&j==0)tmp[u][i][0][l]=min(tmp[u][i][0][l],f[v][i-1][0][l]);
					//建，不加入连通块 
					if(i-1>=0&&l-1>=0)tmp[u][i][0][l]=min(tmp[u][i][0][l],f[v][i-1][j][l-1]);
					//建，新建连通块 
				}
			}
		}
		for(int i=k;i>=0;i--)
			for(int j=n;j>=0;j--)
				for(int l=2;l>=0;l--)
					f[u][i][j][l]=max(f[u][i][j][l],tmp[u][i][j][l]);
	}
}
int d[maxn];

bool hb[maxn],vis[maxn];
int u[maxn],v[maxn];
int dis[maxn];
queue<int>q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)to[i].clear(),d[i]=0;
		for(int i=2;i<=n;i++){
			cin>>u[i]>>v[i];
			to[u[i]].pb(v[i]),to[v[i]].pb(u[i]);
			d[u[i]]++,d[v[i]]++;
		}
		if(n<=15){
			int ans=1e9;
			for(int i=1;i<(1<<n);i++){
				int cnt=0,num=0;
				for(int j=0;j<n;j++){
					if(i&(1<<j))hb[j+1]=1,cnt++,num++;
					else hb[j+1]=0;
				}
				for(int j=2;j<=n;j++){
					if(hb[u[j]]&&hb[v[j]]){
						cnt--;
					}
				}
				if(cnt<=2&&num==k){
					int cur=0;
					while(q.size())q.pop();
					for(int j=1;j<=n;j++){
						if(hb[j])vis[j]=1,q.push(j),dis[j]=0;
						else vis[j]=0;
					}
					while(q.size()){
						int u=q.front();
						q.pop();
						for(int v:to[u]){
							if(vis[v]==0){
								vis[v]=1;
								dis[v]=dis[u]+1;
								q.push(v);
								cur=max(cur,dis[v]); 
							}
						}
					}
					ans=min(ans,cur);
				}
			}
			cout<<ans<<"\n";
		}else
		if(n<=100){
			int root=1;
			for(int i=1;i<=n;i++){
				if(d[i]==1){
					dp1(i,0);
					root=i;
					break;
				}
			}
			int ans=1e9;
			for(int i=0;i<=n;i++){
				for(int l=0;l<=2;l++){
					ans=min(ans,f[root][k][i][l]);
				}
			}	
			cout<<ans<<"\n";
		}
	}
}
