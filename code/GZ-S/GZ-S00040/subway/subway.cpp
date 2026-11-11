//GZ-S00040 贵阳市第一中学 敖翔蓝天 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
ll koudting[500005],a[N][N],G[N][20005],hdl[500005],cnt=1;
vector<ll> jd[500005];
ll c,n,m,d,q,w,v;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++){
		cin>>koudting[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			cin>>v>>w;
			jd[v].push_back(i);
			G[i][v]=w;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:jd[i]){
			hdl[cnt++]=j;
		}
		for(int j=1;j<cnt;j++){
			for(int k=j+1;k<cnt;k++){
				a[hdl[j]][hdl[k]]=a[hdl[k]][hdl[j]]=min(a[hdl[j]][hdl[k]],G[hdl[j]][i]+G[hdl[k]][i]);
			}
		}
		cnt=1;
	}
	for(int i=1;i<=n;i++){
		a[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--){
		ll ans=INT_MAX,l,r;
		cin>>l>>r;
		for(auto u:jd[l]){
			for(auto uu:jd[r]){
				ans=min(ans,a[u][uu]+G[u][l]+G[uu][r]);
			}
		}
		cout<<ans+koudting[l]+koudting[r]<<'\n';
	}
	return 0;
}
