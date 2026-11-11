#include<bits/stdc++.h>
using namespace std;
#define int  long long
const int N=1e5+10,M=505,INF=1e18;
int n,m,d,q,w[N],f[M][M];
//vector<vector<int>>f;
struct P{
	int l,t;
}; 
vector<P>v[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	//f.assign(n+1,vector<int>(n+1,INF));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=(i==j)?0:INF;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;i<=k;j++){
			int a,b;
			cin>>a>>b;
			v[a].push_back({i,b});
		}
	}
	for(int i=1;i<=m;i++){
		int z=v[i].size();
		for(int j=0;j<z;j++){
			for(int k=0;k<z;k++){
				int u=v[i][j].l,w_=v[i][k].l;
				f[u][w_]=min(f[u][w_],v[i][j].t+v[i][k].t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(f[i][k]==INF){
				continue;
			}
			for(int j=1;j<=n;j++){
				if(f[k][j]==INF){
					continue;
				}
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=INF;
		for(auto &i:v[x]){
			for(auto &j:v[y]){
			    ans=min(ans,i.t+f[i.l][j.l]+j.t);
		    }	
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	
	return 0;
}
 
 
 
 
 
 
 
 
