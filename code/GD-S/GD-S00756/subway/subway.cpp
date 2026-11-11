#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,Q=1e5+5;
int c,n,m,d,q,w[N],a[500][N],t[500][N],k[N],x[Q],y[Q],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	cout<<ans;
	return 0;
}
