//GZ-S00182 遵义市第五十三中学 王前进
#include<bits/stdc++.h>
using namespace std;
const int M=1e4;
int c,n,d,t,x[M],f[M][1000];
bool vis[M];
int bfs(int u,int st,int sum){
	if(f[u][st]) return f[u][st];
	if(x[u]==x[n]){
		return 0;
	}
	for(int i=1;i<=st;i++){
		if(!vis[i]){
			if(i+st>n) continue;
			vis[i]=1;
			f[i][i+st]=min(f[i][i+st],dfs(i,st+i,sum+x[i]));
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<bfs(0,0,0)<<"\n";
	}
}
