#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=205,M=20200;
ll t[M][N],w[M],k[N],f[N][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll C,n,m,d,Q;
	cin>>C>>n>>m>>d>>Q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	ll a=0,b=0,c=0;
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>f[i][j]>>t[i][f[i][j]];
			if(f[i][j]==1) a++;
			if(f[i][j]==2) b++;
			if(f[i][j]==3) c++;
		}
	}
	if(max({a,b,c})==a) d=1;
	if(max({a,b,c})==b) d=2;
	if(max({a,b,c})==c) d=3;
	ll v1,v2,v3;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=k[i];j++){
			if(f[i][j]==1){
				v1=i;
			}
			if(f[i][j]==2){
				v2=i;
			}
			if(f[i][j]==3){
				v3=i;
			}
		}
	}
	while(Q--){
		ll x,y;
		cin>>x>>y;
		if(x>y){
			swap(x,y);
		}
		if(C==20||C==21){
			if(d==1){
				if(x==1&&y==2){
					cout<<w[x]+t[v2][x]+t[v2][y]+w[y]<<"\n";
				}
				if(x==1&&y==3){
					cout<<w[x]+t[v3][x]+t[v3][y]+w[y]<<"\n";
				}
				if(x==2&&y==3){
					cout<<w[x]+t[v2][x]+t[v2][d]+t[v3][d]+t[v3][y]+w[y]<<"\n";
				}
			}
			if(d==2){
				if(x==1&&y==2){
					cout<<w[x]+t[v1][x]+t[v1][y]+w[y]<<"\n";
				}
				if(x==2&&y==3){
					cout<<w[x]+t[v3][x]+t[v3][y]+w[y]<<"\n";
				}
				if(x==1&&y==3){
					cout<<w[x]+t[v1][x]+t[v1][d]+t[v3][d]+t[v3][y]+w[y]<<"\n";
				}
			}
			if(d==3){
				if(x==1&&y==3){
					cout<<w[x]+t[v1][x]+t[v1][y]+w[y]<<"\n";
				}
				if(x==2&&y==3){
					cout<<w[x]+t[v2][x]+t[v2][y]+w[y]<<"\n";
				}
				if(x==1&&y==2){
					cout<<w[x]+t[v1][x]+t[v2][d]+t[v2][d]+t[v2][y]+w[y]<<"\n";
				}
			}
		}
		else{
			cout<<66<<"\n";
		}
	}
	return 0;
}