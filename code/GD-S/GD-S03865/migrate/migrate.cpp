#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int c,t;
long long n,d,a[N],f[N][N],vis[N][N],ans;
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c==11||c==12){
		long long x=d/(a[2]-a[1]);
		if(a[2]-a[1]>=d||x+x-1>=n) cout<<0<<'\n';
		else cout<<n-(x+x-1)<<'\n';
		return;
	}
	memset(f,0x3f3f3f3f,sizeof(f));
	memset(vis,0,sizeof(vis));
	ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(abs(a[i]-a[j])<=d)
				f[i][j]=f[j][i]=vis[i][j]=vis[j][i]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(f[i][k]+f[k][j]==f[i][j]) vis[i][j]++;
				else if(f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
					vis[i][j]=1;
				}
			}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(vis[i][j]==2) ans++;
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) work();	
	return 0;
}
