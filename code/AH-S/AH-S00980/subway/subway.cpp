#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[N],k[N],a[N][M],t[N][M],mp[100005],jl;
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(mp[a[i][j]]!=0){
				jl=a[i][j];
			}
			mp[a[i][j]]=k[i];
		}
	}
	for(int i=1;i<=q;i++){
		int xr,yr;
		cin>>xr>>yr;
		if(n==1){
			cout<<w[xr]+w[yr]+t[1][xr]+t[1][yr]<<endl;
		}
		if(n==2){
			if(mp[xr]==mp[yr]||xr==jl||yr==jl){
				cout<<w[xr]+w[yr]+t[mp[xr]][xr]+t[mp[yr]][yr]<<endl;
			}else{
				cout<<w[xr]+w[yr]+t[mp[xr]][xr]+t[mp[xr]][jl]+t[mp[yr]][jl]+t[mp[yr]][yr]<<endl;
			}
		}
	}
	return 0;
}
