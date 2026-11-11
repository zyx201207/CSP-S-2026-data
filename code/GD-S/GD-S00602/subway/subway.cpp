#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	int k,a[500005],t[500005];
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			if(i==j){
				dis[i][j]=0;
				dis[j][i]=0;
			}
			else{
				dis[i][j]=1e9;
				dis[j][i]=1e9;
			}
		}
	}
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;++j){
			for(int p=j+1;p<=k;++p){
				dis[a[j]][a[p]]=t[j]+t[p];
				dis[a[p]][a[j]]=t[j]+t[p];
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=m;++j){
			for(int k=1;k<=m;++k){
				if(dis[i][j]+dis[j][k]<dis[i][k])dis[i][k]=dis[i][j]+dis[j][k];
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
