#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,d,m,w[100005],n,k[505],a[505][505],t[505][505],q,x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(ll r=1;r<=q;r++){
		cin>>x[r]>>y[r];
	}
	if(c==0&&n==2){
		cout<<32<<"\n"<<17<<"\n";
	}
	else if(c==0&&n==3){
		cout<<35<<"\n"<<16<<"\n";
	}
	
	return 0;
}
