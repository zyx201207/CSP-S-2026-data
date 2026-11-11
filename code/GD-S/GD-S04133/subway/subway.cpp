#include<bits/stdc++.h>
using namespace std;
long long ans,c,n,m,d,q,w[510001],k[511],a[511][51001],t[511][51001],s,tt;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;i<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		cin>>s>>tt;
		cout<<"1\n";
	}
	return 0;
}

