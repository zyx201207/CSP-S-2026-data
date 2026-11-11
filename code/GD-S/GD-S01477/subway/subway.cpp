#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool aaa;
int C,n,m,D,q;
ll w[500010],f[520][520];
struct N{
	int x;
	ll t;
};
vector<N> p[500010];
int len[510];
bool bbb;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cout<<(&bbb-&aaa)/1048576.0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>m>>n>>D>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			int x,t;
			cin>>x>>t;
			p[x].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)f[i][i]=0;
	for(int x=1;x<=n;x++){
		for(int i=0;i<p[x].size();i++){
			for(int j=i+1;j<p[x].size();j++){
				N u=p[x][i],v=p[x][j];
				f[u.x][v.x]=f[v.x][u.x]=min(f[u.x][v.x],u.t+v.t);
			}
		}
	} 
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
//		}
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=0;i<p[x].size();i++){
			for(int j=0;j<p[y].size();j++){
				N u=p[x][i],v=p[y][j];
				ans=min(ans,f[u.x][v.x]+u.t+v.t);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

