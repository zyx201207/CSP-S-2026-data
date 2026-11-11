#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll c,n,m,d,q,w[N],a[N][N],t[N][N],dist[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dist,0x3f,sizeof(dist));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++) dist[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++) cin>>a[i][j]>>t[i][j];
		dist[a[i][1]][a[i][2]]=t[i][1]+t[i][2],dist[a[i][2]][a[i][1]]=t[i][1]+t[i][2];
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y]+dist[x][y];
		cout<<ans<<"\n";
	}
	return 0;
}

