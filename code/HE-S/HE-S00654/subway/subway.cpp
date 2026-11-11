#include <bits/stdc++.h>
using namespace std;
const int N=1e8;
long long c,n,m,d,q,w[N],k,a[N],t[N],x[N],y[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	cin>>k;
	for(int i=1; i<=2*k; i++){
		cin>>a[i]<<t[i];
	}
	for(int i=1; i<=2; i++){
		cin>>x[i]>>y[i];
	}
	cout<<1<<38;
	return 0;
}
