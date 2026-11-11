#include<bits/stdc++.h>
#define int long long
#define uint long long
using namespace std;
int c,n,m,a[1000010],b[7891][7891],z;
void solve(){
	cin>>n>>m,memset(b,0,sizeof b),z=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-3;i++)
			if(a[i+3]-a[i]>m&&a[i+1]-a[i]<=m&&a[i+3]-a[i-1]<=m&&a[i+2]-a[i]<=m&&a[i+3]-a[i+2]<=m)
				for(int ii=1;ii<=i;ii++)
					for(int jj=i+3;jj<=n;jj++) b[ii][jj]++;
	for(int i=1;i<=n;i++)
		for(int j=i+3;j<=n;j++)
			if(b[i][j]==1) z++;
	for(int i=1;i<=n;i++,cout<<'\n')	
		for(int j=1;j<=n;j++) cout<<b[i][j]<<' ';
	cout<<z<<'\n';
}
signed main(){
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int T=1;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}