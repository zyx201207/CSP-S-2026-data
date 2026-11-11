#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,w[1000005],k[505],a[505][50005],t[505][50005],x[100005],y[100005],tme=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;++i){
		cin>>w[i];
	}
	for(ll i=1;i<=n;++i){
		cin>>k[i];
		for(ll j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(ll i=1;i<=q;++i){
		cin>>x[i]>>y[i];
	}
	for(ll i=1;i<=q;++i){
		for(ll j=1;j<=n;++j){
			bool f=0;
			for(ll l=1;l<=k[j];++l){
				if(x[i]>y[i]){
					f=1;
					break;
				}
				if(x[i]==a[j][l]){
					tme+=(w[a[j][l]]+t[j][l]);
					++x[i];
				}
			}
			if(f){
				tme+=(w[a[j][k[j]]]+t[j][k[j]]);
				break;
			}
		}
		cout<<tme<<endl;
	}
	return 0;
}
