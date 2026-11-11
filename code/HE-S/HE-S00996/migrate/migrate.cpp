#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5000,INF=1e18;
ll m,n;
ll g[N][N],c[N][N];
ll a[N];
ll cnt=0;
ll r,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cin>>r>>t;
	while(t--){
	cin>>n>>m;
	cnt=0;
	for(ll i=0;i<n;i++) for(ll j=i+1;j<n;j++) g[i][j]=INF,c[i][j]=0;
	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++) for(ll j=i+1;j<n;j++) if(a[j]-a[i]<=m) g[i][j]=1,c[i][j]=1;
	 for(ll i=0;i<n;i++) for(ll j=i+1;j<n;j++)for(ll x=i+1;x<j;x++){
		if(g[i][x]+g[x][j]==g[i][j]) c[i][j]++;
		if(g[i][x]+g[x][j]<g[i][j]) g[i][j]=g[i][x]+g[x][j],c[i][j]=1;
	}
	for(ll i=0;i<n;i++) for(ll j=i+1;j<n;j++) if(c[i][j]==2) cnt++;
	//for(ll i=0;i<n;i++) for(ll j=i+1;j<n;j++) cout<<g[i][j]<<" "<<i<<" "<<j<<endl;
	cout<<cnt<<endl;
}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
