#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
const ll inf=1e18;
ll n,c,m,d,q,w[N],k[N],a[505][N],t[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a[i][j]=inf;
		}
	}
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i]*2;j++){
			cin>>a[i][j]>>t[i];
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		for(int k=0;k<m;k++){
			for(int i=0;i<=m;i++){
				for(int j=0;j<=m;j++){
					if(a[i][k]!=inf&&a[k][j]!=inf){
						a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
					}
				}
			}
		}
		cout<<a[x][y];
	}
	return 0;
}
