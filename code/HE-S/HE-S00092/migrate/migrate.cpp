#include<bits/stdc++.h>
using namespace std;
const int N =1000;
int f[N][N];
int n,c,t;
int ans =0;
int d;
int a[N];
int kk[N][N]; 
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i =1;i<=n;i++)cin>>a[i];
	memset(f,0x3f,sizeof f);
	memset(kk,0,sizeof kk);
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i =1;i<=n;i++){
			if(f[i][k]==0x3f3f3f3f)continue;
			for(int j =1;j<=n;j++){
				if(f[k][j]==0x3f3f3f3f)continue;
				if(f[i][j]>d||f[i][k]>d||f[k][j]>d)continue;	
				if(f[i][k]+f[k][j]==f[i][j])kk[i][j]+=2;
				if(f[i][k]+f[k][j]<f[i][j])f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	} 
	for(int k=1;k<=n;k++){
		for(int i =1;i<=n;i++){
			if(kk[k][i]==2)ans++;
		}
	} 
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i =1;i<=t;++i){
		solve();
	}
}
