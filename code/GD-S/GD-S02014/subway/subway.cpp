#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,m,n,d,q,x,y,a[100005],t[100005],w[100005],f[10005][10005],k;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(f,0x3f,sizeof(f));
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(int j=1;j<=k;j++)
			for(int l=1;l<=k;l++) f[a[j]][a[l]]=min(f[a[j]][a[l]],t[j]+t[l]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int l=1;l<=n;l++) f[j][l]=min(f[j][l],f[j][i]+f[i][l]);
	while(q--){
		cin>>x>>y;
		cout<<w[x]+f[x][y]+w[y]<<"\n";
	}
	return 0;
}
