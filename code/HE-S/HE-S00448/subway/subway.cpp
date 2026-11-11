#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
#define il inline
int c,n,m,d,q;
int w[N];
int cnt=0;
int f[510][510];
vector<pair<int,int>> pt[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	int bg=clock();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	cnt=0;
	for(int i=1,k;i<=n;i++){
		++cnt;
		cin>>k;
		for(int j=1,p,t;j<=k;j++){
			cin>>p>>t;
			pt[p].emplace_back(cnt,t);
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		for(auto p1:pt[i]){
			for(auto p2:pt[i]){
				int u=p1.first,v=p2.first;
				if(u==v) {	
					continue;
				}
				f[u][v]=min(p2.second+p1.second,f[u][v]);
				f[v][u]=min(p1.second+p2.second,f[v][u]);
			}
		}
	}
	for(int i=1;i<=cnt;i++) f[i][i]=0;
	for(int k=1;k<=cnt;k++){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=cnt;i++){
//		for(int j=1;j<=cnt;j++){
//			cout<<f[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	while(q--){
		int u,v,ans=LLONG_MAX;
		cin>>u>>v;
		for(auto p1:pt[u]){
			for(auto p2:pt[v]){
				int k1=p1.first,k2=p2.first;
				ans=min(ans,f[k1][k2]+p1.second+p2.second);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
//	cerr<<clock()-bg;
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

