#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e2+10;
ll ans[N][N],i,j,d[N][N],w[N],n,m,c,l,r,q,t[N],k,W[N],T[N];
void Floyd(){
	memset(ans,0x3f,sizeof(ans));
	for(i=1;i<=m;i++) ans[i][i]=0;
	for(i=1;i<=m;i++) for(j=1;j<=m;j++) if(d[i][j]!=0x3f3f3f3f3f3f3f3f) ans[i][j]=ans[j][i]=d[i][j];
	for(i=1;i<=m;i++) for(j=1;j<=m;j++) for(k=1;k<=m;k++) ans[i][j]=min(ans[i][k]+ans[k][j],ans[i][j]);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(d,0x3f,sizeof(d));
    cin>>c>>n>>m>>c>>q;
    for(i=1;i<=m;i++) cin>>t[i];
    for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++) cin>>W[j]>>T[j];
		for(j=1;j<=k;j++) for(ll J=1;J<=k;J++) if(j!=J) d[W[j]][W[J]]=T[j]+T[J];
	}
    Floyd();
    while(q--){
		cin>>l>>r;
		cout<<ans[l][r]+t[l]+t[r]<<"\n";
	}
    return 0;
}
