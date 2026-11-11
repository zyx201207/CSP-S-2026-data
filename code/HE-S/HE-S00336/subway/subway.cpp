#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+500;
int c,n,m,d,q;
int w[N],a[550][N],t[550][N],x,y,k[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i]*2;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int ans=0;
		ans+=t[x][y]*(y-x);
		cout<<ans<<"\n";
	}
	return 0;
}
