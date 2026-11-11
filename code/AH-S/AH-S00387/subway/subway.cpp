#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
LL c,n,m,d,q;
LL w[N];
LL k[505],a,t[505][N];
LL x,y;
vector<LL> g[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(LL i=1;i<=m;i++) cin>>w[i];
	for(LL i=1;i<=n;i++){
		cin>>k[i];
		for(LL j=1;j<=k[i];j++){
			cin>>a>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		LL sum=0,i=x;
		while(i<y){
			if(i+1<y) sum+=t[i][i+1]+t[i+1][i+1];
			i++;
		}
		LL ans=w[x]+t[x][x]+sum+t[i][y]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
