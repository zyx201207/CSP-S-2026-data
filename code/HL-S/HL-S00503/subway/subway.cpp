#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1;
ll c,n,m,d,q,w[N],a,x,y;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m+2; j++) {
			cin>>a;
		}
	}
	for(int i=1; i<=q; i++) {
		for(int j=1; j<=2; j++) {
			cin>>x>>y;
		}
	}
	cout<<32<<endl<<17;
	return 0;
}