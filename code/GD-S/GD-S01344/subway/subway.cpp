#include<bits/stdc++.h>
using namespace std;
const int NNN=5010;
long long c,n,m,d,q,w[500010],a[NNN][NNN],t[NNN][NNN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=2;i++){
		int kk;
		cin>>kk;
		for(int i=1;i<=kk;i++){
			for(int j=1;j<=kk;j++){
			cin>>a[i][j]>>t[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		long long ans=0;
		ans=w[x]+w[y];
		for(int j=1;j<=n;j++){
			ans+=t[i][j]; 
		}
		cout<<ans<<'\n';
	} 
	return 0;
}//²»ÔËÐÐ£¿ 
//. 
