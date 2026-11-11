#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+7;
int qwe,n,m,d,p,q,w[N],b[600][600],c[600];
struct dd{
	int a,t;
};
vector<dd> a[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(b,0x3f3f3f,sizeof(b));
	memset(c,0x3f3f3f,sizeof(c));
	cin>>qwe>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k; 
		for(int j=1;j<=k;j++){
			int u,t;cin>>u>>t;
			a[u].push_back({i,t});
			c[i]=min(c[i],t);
		}
	}
	for(int i=1;i<=m;i++){
		for(auto v:a[i])
		for(auto u:a[i]){
			if(v.a!=u.a) {
				if(b[v.a][u.a]>v.t){
					b[v.a][u.a]=v.t;
				}
				if(b[u.a][v.a]>u.t){
					b[u.a][v.a]=u.t;
				}
			}else b[u.a][v.a]=0;
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	b[i][j]=min(b[i][k]+b[k][j],b[i][j]);
	
/*	for(int i=1;i<=n;i++)
	{
		cout<<i<<"\n"; 
		for(int j=1;j<=n;j++){
			cout<<i<<" "<<j<<" "<<b[i][j]<<"\n"; 
		}
	}
	 */
	
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(auto v:a[x])
		for(auto u:a[y]){
			if(ans>b[v.a][u.a]+u.t+v.t){
				ans=b[v.a][u.a]+u.t+v.t;
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
