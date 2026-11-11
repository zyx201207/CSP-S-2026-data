#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5005;
ll a[maxn*maxn];
int l[maxn*maxn],dis[maxn][maxn];
int ok[maxn][maxn];
void slv() {
	int n;
	ll d; cin>>n>>d;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
	}
	for(int i=1,j=1;i<=n;++i) {
		while(j<i&&a[i]-a[j]>d) ++j;
		l[i]=j;
		ok[i][i]=1; dis[i][i]=0;
	}
	int ans=0;
	for(int i=2;i<=n;++i) for(int j=1;j+i-1<=n;++j) {
		int j1=j+i-1;
		if(j>=l[j1]) {
			dis[j][j1]=1; ok[j][j1]=1;
			continue;
		}
		if(dis[j][l[j1]]==1e9) continue;
		dis[j][j1]=1e9; ok[j][j1]=0;
		for(int d=0;d<=2&&l[j1]+d<j1;++d) {
			if(dis[j][l[j1]+d]==dis[j][l[j1]]) ok[j][j1]+=ok[j][l[j1]+d];	
			dis[j][j1]=dis[j][l[j1]]+1;
		}
		if(ok[j][j1]==2) ++ans;
		ok[j][j1]=min(ok[j][j1],3);
	}
//	for(int i=1;i<=n;++i) for(int j=i;j<=n;++j) cout<<ok[i][j]<<" \n"[j==n];
	cout<<ans<<'\n';
}
void slv2() {
	int n;
	ll d; cin>>n>>d;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
	}
	int l=1;
	while(l<n&&a[l]-a[1]<=d) ++l;
	--l;
	if(l<=2) cout<<0<<'\n';
	else cout<<max(0,n-(l-1)*2+1)<<'\n';
	
}
int main() {
//	system("fc migrate.out .ans");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,T; cin>>c>>T;
	if(c<=10) while(T--) slv();
	else while(T--) slv2();
	return 0;
} 
