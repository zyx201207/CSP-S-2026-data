#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long c,n,m,d,q,w[N],t[511][N*2],k[501],tt;
long long a[510][510];
vector<long long>v[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>tt;
			v[tt].push_back(i);
			scanf("%lld",&t[i][tt]);
		}
	}
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++){
		if(i!=j) a[i][j]=1e18;
	}
	for(int s=1;s<=m;s++){
		if(v[s].size()>1){
			for(int i=0;i<v[s].size();i++){
				for(int j=i+1;j<v[s].size();j++){
					a[v[s][i]][v[s][j]]=a[v[s][j]][v[s][i]]=t[v[s][i]][s]+t[v[s][j]][s];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
			for(int k=1;k<=n;k++)
				if(i!=k && j!=k){
					a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
				}
	while(q--){
		long long x,y,ys,sy;
		cin>>x>>y;
		long long mint=1e18;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				if(mint>=a[v[x][i]][v[y][j]]){
					mint=min(mint,a[v[x][i]][v[y][j]]);
					ys=v[x][i]; sy=v[y][j];
				}
			}
		}
		cout<<w[x]+w[y]+mint+t[ys][x]+t[sy][y]<<'\n';
	}
	
	
	
	return 0;
} 
