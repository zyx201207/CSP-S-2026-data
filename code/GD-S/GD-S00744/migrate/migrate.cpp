#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int t,n,d,a[N],f[N][2];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		for(int u=1;u<=n;u++){
			int x=lower_bound(a+1,a+n+1,a[u]-d)-a;
			if(upper_bound(a+1,a+n+1,a[x]+d)-a-1==u){
				f[u][0]=f[x][0]+1,f[u][1]=f[x][1];
				int y=lower_bound(a+1,a+n+1,a[x]-d)-a;
				f[u][1]-=(y<x-1)*f[y+1][0];
			}
			f[u][1]+=(x<u-1)*f[x+1][0],ans+=f[u][1];
//			cout<<u<<' '<<x<<' '<<f[u][0]<<' '<<f[u][1]<<' '<<(x<u-1)*f[x+1][0]<<'\n';
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)f[i][0]=f[i][1]=0;
	}
}
/*
0 1
10 3
0 1 2 3 4 5 6 7 8 9
*/
