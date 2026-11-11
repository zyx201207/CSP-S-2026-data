#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,Q,o,ans,w[1000001],d[1000001],f[505][505];
struct tt{
	int x,y;
};
bool operator < (tt n,tt m){
	return n.y>m.y;
}
vector<tt>l[600001];
priority_queue<tt>q;
void SPF(int jk){
	while(q.size()) q.pop();
	q.push({jk,0});
	for(int i=1;i<=n+m;i++) d[i]=1e17;
	for(int i=1;i<=n;i++){
		if(f[jk-m][i]!=0) d[i+m]=f[jk-m][i];
		q.push({i+m,d[i+m]});
	}
	d[jk]=0;
	while(q.size()){
		tt k=q.top();
		q.pop();
		if(k.y>d[k.x]) continue;
		for(int i=0;i<l[k.x].size();i++){
			int u=k.x,v=l[k.x][i].x,t=l[k.x][i].y;
			if(d[v]>k.y+t){
				d[v]=k.y+t;
				q.push({v,d[v]});
			}
		}
	}
	for(int i=1;i<=n;i++) f[i][jk-m]=d[i+m];
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int C;
	cin>>C>>n>>m>>o>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			l[m+i].push_back({x,t});
			l[x].push_back({m+i,t});
		}
	}
	for(int i=1;i<=n;i++){
		SPF(m+i);
	}
	for(int i=1;i<=Q;i++){
		int u,v;
		cin>>u>>v;
		ans=1e17;
		for(int j=0;j<l[u].size();j++){
			for(int la=0;la<l[v].size();la++){
				int o=l[u][j].x,p=l[v][la].x;
				int sum=f[o-m][p-m]+l[u][j].y+l[v][la].y+w[u]+w[v];
				ans=min(ans,sum);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
