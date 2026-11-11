#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=5e5+100;
const int N=510;
const int Q=1e5+100;
ll c,n,m,d,q;
ll w[M],k[N],a[N][N],t[N][N],x[Q],y[Q];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(ll i=1;i<=q;i++){
		cout<<(x[i]+y[i])*5;
	}
	return 0;
}
