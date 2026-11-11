#include<bits/stdc++.h>
using namespace std;
const int M=25*1e4,N=505,K=1e6+10;
int c,n,m,d,q,w[M],k[N],a[K],t[K],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i]>>t[i];
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
