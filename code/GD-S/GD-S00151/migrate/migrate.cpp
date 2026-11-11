#include<bits/stdc++.h>
using namespace std;
long long n,id,T,ans,m,a[100005];
long long f[5005][5005],g[5005][5005];
void solve(){
	cin>>n>>m;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			if(i!=j) f[i][j]=100000000,g[i][j]=0;
			else f[i][j]=0,g[i][j]=1;
		}
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
//			cout<<i<<","<<j<<" "<<f[i][j]<<" "<<g[i][j]<<endl;
			if(g[i][j]==2) ans++;
			for(int k=j;k<=n;k++){
				if(a[k]-a[j]>m) break;
				if(f[i][j]+1<f[i][k]) f[i][k]=f[i][j]+1,g[i][k]=0;
				if(f[i][j]+1==f[i][k]) g[i][k]+=g[i][j];
//				cout<<f[i][j]+1<<" "<<f[i][k]<<" "<<g[i][k]<<" "<<g[i][j]<<endl;
			}
		}
	}cout<<ans<<endl;
	return ;
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>id>>T;
	while(T--) solve();
} 
