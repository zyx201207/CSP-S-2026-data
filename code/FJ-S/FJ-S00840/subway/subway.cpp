#include<bits/stdc++.h>
using namespace std;
const int N=510,M=500010;
const long long INF=1e18;
int c,n,m,d,q,k[N];
long long w[M],f[N][N];
vector<long long>a[N],t[N];
vector<int>v[M];
map<int,long long>mp[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			mp[a[i][j]][i]=t[i][j];
			v[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=INF;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int l=0;l<v[i].size();l++){
				if(j!=l){
					int i1=v[i][j],i2=v[i][l];
					f[i1][i2]=min(f[i1][i2],mp[i][i1]+mp[i][i2]);
					f[i2][i1]=f[i1][i2];
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=INF;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				ans=min(ans,mp[x][v[x][i]]+mp[y][v[y][j]]+f[v[x][i]][v[y][j]]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
