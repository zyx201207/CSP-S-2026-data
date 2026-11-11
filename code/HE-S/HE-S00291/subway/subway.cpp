#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+100;
ll c,n,m,d,q,w[N],k[N],a[1090][1090],t[1090][1090],s[1090][1090],z[1090][1090];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
		for(ll j=1;j<=k[i];j++){
			for(ll K=1;K<=k[i];K++){
				s[a[i][j]][a[i][K]]=t[i][a[i][j]]+t[i][a[i][K]];
			}
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=m;j++){
			if(s[i][j]==0){
				s[i][j]=99999999;
			}
		}
	}
	for(ll l=1;l<=m;l++){
		for(ll i=1;i<=m;i++){
			for(ll j=1;j<=m;j++){
				s[i][j]=min(s[i][j],s[i][l]+s[j][l]);
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		cout<<s[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
