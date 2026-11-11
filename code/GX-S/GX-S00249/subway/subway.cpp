#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e9+10,NINF=-1e9-10,N=1010,M=5*1e5+10;
ll c,n,m,d,q,a,t,x,y,ans;
ll w[M],k[N],dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=0;i<=m+n;i++){
		for(ll j=i;j<=m+n;j++){
			if(i==j)dis[i][j]=dis[j][i]=0;
			else dis[i][j]=dis[j][i]=INF;
		}
	}
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a>>t;
			dis[a][m+i]=min(dis[a][m+i],t);
			dis[m+i][a]=min(dis[m+i][a],t);
		}
	}
	for(ll k=1;k<=m+n;k++){
		for(ll i=1;i<=m+n;i++){
			for(ll j=1;j<=m+n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	for(ll i=1;i<=q;i++){
		cin>>x>>y;
		ans=w[x]+w[y]+dis[x][y];
		cout<<ans<<endl;
	}
	
	
	return 0;
}
