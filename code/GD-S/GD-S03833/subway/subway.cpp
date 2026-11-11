#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],k[500],a[500005],t[500005],x[100005],y[100005];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[j]>>t[j];
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	if(c==7||c==8){
		for(int i=1;i<=q;i++){
			
		}
	}
	return 0;
}
