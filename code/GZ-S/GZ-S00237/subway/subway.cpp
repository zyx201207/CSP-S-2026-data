//GZ-S00237ÔøÖÂÔ¶ 
#include<bits/stdc++.h>
using namespace std;
int const M=5e5+5,N=505;
int w[M],k[N],a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,t;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<t*2<<'\n';
	}
	return 0;
}
