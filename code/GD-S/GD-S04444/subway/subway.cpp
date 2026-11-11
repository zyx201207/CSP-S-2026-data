#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500000],k[500],a[500][500000],t[500][500000],x,y,r;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	while(cin>>x>>y){

	}
	return 0;
}
