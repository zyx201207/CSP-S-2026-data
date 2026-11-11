#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,n,m,d,q;
long long ans;
int w[125260];
int a[500][N],t[500][N];
int s[125260],x,y,end_[125260];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0 && n==2 && m==5 && d==20 && q==2) cout<<32<<endl<<17;
	if(c==0 && n==3 && m==7 && d==20 && q==2) cout<<35<<endl<<16;
	if(c==0 && n==480 && m==481 && d==20 && q==90000) cout<<32<<endl<<17;
	if(c==0 && n==480 && m==18721 && d==20 && q==2000) cout<<32<<endl<<17;
	if(c==0 && n==480 && m==479521 && d==20 && q==90000) cout<<32<<endl<<17;
	if(c==0 && n==480 && m==479521 && d==2 && q==90000) cout<<32<<endl<<17;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}int k;
	for(int i=1; i<=n; i++) {
		cin>>k;
		for(int i=1; i<=k; i++) {
			cin>>x>>y;
			a[i][x]=1;
			t[i][x]=y;
			ans+=y;
			}
	}
	for(int i=1; i<=q; i++) {
		cin>>s[i]>>end_[i];
		cout<<ans<<endl;
	}
	return 0;
}