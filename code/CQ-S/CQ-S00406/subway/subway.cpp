#include<bits/stdc++.h>
#define int long long
using namespace std;

int cc;
int n,m,d,q;
int w[500010];
int k1[500010];
vector<int> a[500010],t[500010]; 
int g[600][600];
int k2;
int u,u1;
int T;

int v[600][600];
vector<int> v1[500010];

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k1[i];
		k2=k2+k1[i];
		for(int j=1;j<=k1[i];j++){
			cin>>u>>u1;
			a[i].push_back(u);
			t[i].push_back(u1);
			if(T==0) T=u1;
			else if(T!=u1) T=-1;
		}
	}
	
	if(T!=-1){
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i].size();j++){
				v1[a[i][j]].push_back(i);
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				v[i][j]=1e9;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<v1[i].size();j++){
				for(int k=0;k<v1[i].size();k++){
					if(v1[i][j]==v1[i][k]) continue;
					v[v1[i][j]][v1[i][k]]=1;
					v[v1[i][k]][v1[i][j]]=1;
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(v[i][j]==1) continue;
				for(int k=1;k<=n;k++){
					v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
				}
			}
		}
		while(q--){
			cin>>u>>u1;
			int ans=1e9;
			for(int i=0;i<v1[u].size();i++){
				for(int j=0;j<v1[u1].size();j++){
					int x=v1[u][i],y=v1[u1][j];
					ans=min(ans,v[x][y]);
				}
			}
			cout<<(ans+1)*T*2+w[u]+w[u1]<<"\n";
		}
		return 0;
	}	
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j) continue;
				g[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++){		
			for(int j=0;j<a[i].size();j++){
				for(int k=0;k<a[i].size();k++){
					int x=a[i][j],y=a[i][k];
					int t1=t[i][j],t2=t[i][k];
					g[x][y]=min(g[x][y],t1+t2);
					g[y][x]=min(g[y][x],t1+t2);
				}
			}	
		}
		
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=m;k++){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		
		while(q--){
			cin>>u>>u1;
			cout<<g[u][u1]+w[u]+w[u1]<<"\n";
		}
	return 0;
} 
