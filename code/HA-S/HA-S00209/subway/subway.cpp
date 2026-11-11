#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,M=5e5+10,inf=1e16,E=30;
pair<int,int> vec[M][E];
ll c,n,m,d,q,w[M],a[N][N],idx[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1,x;i<=n;i++){
		cin>>x;
		int a,b;
		for(ll j=1;j<=x;j++){
			cin>>a>>b;
			vec[a][++idx[a]]={b,i};
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j) a[i][i]=0;
			else a[i][j]=inf;
		}
	}
	for(ll i=1;i<=m;i++){
		for(int c=1;c<=idx[i];c++){
			for(int d=1;d<=idx[i];d++){
				pair<int,int> t1=vec[i][c],t2=vec[i][d];
				a[t1.second][t2.second]=min(a[t1.second][t2.second],((long long)t1.first+t2.first));
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		}
	}
	for(ll i=1,x,y;i<=q;i++){
		cin>>x>>y;
		ll ans=1e18;
		for(int c=1;c<=idx[x];c++){
			for(int d=1;d<=idx[y];d++){
				pair<int,int> t1=vec[x][c],t2=vec[y][d];
				ans=min(ans,a[t1.second][t2.second]+t1.first+t2.first);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3




