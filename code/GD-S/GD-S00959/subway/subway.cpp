#include<bits/stdc++.h>
using namespace std;
#define int long long
int zzz,n,m,d,q,w[500005],k,a[505][50005],t[505][50005],x[100005],y[100005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>zzz>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	return 0;
}
