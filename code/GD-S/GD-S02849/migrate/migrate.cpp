#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,x[N],f[5005][5005],p[5005][5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			p[i][j]=0;
			f[i][j]=1e15;
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&abs(x[i]-x[j])<=d)f[i][j]=1;
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&f[i][j]==f[i][k]+f[k][j]){
//			cout<<i<<' '<<j<<' '<<k<<'\n'; 
			p[i][j]+=p[i][k]+p[k][j]+1;
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++)cout<<p[i][j]<<' ';
//			cout<<'\n';
//		}
		int ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(p[i][j]==2)ans++;
		cout<<ans/2<<'\n';
	}
	return 0;
} 

