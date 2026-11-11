#include<bits/stdc++.h>
using namespace std;
const int INF=0x7f7f7f7f;
const int N=505,M=1e5+5;
int T[N][M],w[M];
bool p[M];
vector<int>G[N],G1[N];
int y,z=INF,zx=INF;
int dfs(int x,int l,int l1,int x1){
	if(x==y){
		return T[l1][y];
	}
	p[x]=1;
	for(int t:G[l]){
		if(p[t])continue;
		p[t]=1;
		if(t==y){
			z=min(z,T[l][x]+T[l][y]);
			continue;
		}
		for(int d:G1[t]){
			z=min(z,dfs(t,d,l,x)+T[l][x]+T[l1][x]);
		}
	}
	return z;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			G[i].push_back(a);
			if(!G1[a].empty()){
				for(int t:G1[a]){
				if(t==i)break;
				G1[a].push_back(i);
				}
			}
			else G1[a].push_back(i);
			T[i][a]=t;
		}
	}
	while(q--){
		int x;
		cin>>x>>y;
		int ans=INF;
		for(int i=1;i<=n;i++){
			ans=min(ans,dfs(x,i,0,0));
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	
	return 0;
}

