#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+55,inf=2000000000000000000;
ll c,n,m,d,q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll _;
	cin>>c>>_;
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
	
while(_--){
	cin>>n>>m;
	ll ans=0;
	vector<vector<ll>>d(n+2,vector<ll>(n+2,inf));
	vector<vector<ll>>d1(n+2,vector<ll>(n+2,inf));
	vector<vector<ll>>sum(n+2,vector<ll>(n+2,0));
	vector<ll>x(n+2,0);
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(x[i]-x[j])<=m){
				d[i][j]=1;
				d[j][i]=1;
			}
		}
	}	
//	for(int i=1;i<=n;i++)d[i][i]=d1[i][i]=2e18+1;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i<=k&&k<=j){
					d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
				}
			}
		}		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(x[i]-x[j])<=m){
				d1[i][j]=1;
				d1[j][i]=1;
				if(d1[i][j]==d[i][j]){
					sum[i][j]++;
				}
			}
		}
	}	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i<k&&k<j&&i!=j){
					d1[i][j]=min(d1[i][k]+d1[k][j],d1[i][j]);
					if(d1[i][k]+d1[k][j]==d[i][j]){
						sum[i][j]++;
					}
				}
			}
		}		
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(sum[i][j]==2){
//				cout<<i<<"->"<<j<<'\n';
				ans+=(sum[i][j]==2);
			}
		}
	}
	cout<<ans<<'\n';
}
	
	return 0;
}
