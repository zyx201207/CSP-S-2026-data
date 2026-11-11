#include<bits/stdc++.h>
using namespace std;
long long a[305],f[305][305],v[305][305];
int main(){
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
   int c,t;
   cin>>c>>t;
   while(t--){
	   int n,d;
	   cin>>n>>d;
	   for(int i=1;i<=n;i++){
		   for(int j=1;j<=n;j++){
			   f[i][j]=1e18+1;
			   f[j][i]=1e18+1;
			   v[j][i]=0;
			   v[i][j]=0;
		   }
	   }
	   for(int i=1;i<=n;i++){
		   cin>>a[i];
		   for(int j=i-1;j>=1;j--){
			   if(a[i]-a[j]>d) break;
			   //cout<<j<<" "<<i<<"\n";
			   f[j][i]=0;
			   v[j][i]=1;
		   }
	   }
	   for(int i=1;i<=n;i++){
		   for(int j=i+1;j<=n;j++){
			   for(int k=i+1;k<j;k++){
				   if(f[i][j]==f[i][k]+f[k][j]+1){
					   v[i][j]++;
					   //cout<<"p";
				   }
				   if(f[i][j]>f[i][k]+f[k][j]+1){
					   f[i][j]=f[i][k]+f[k][j]+1;
					   v[i][j]=1;
					   //cout<<"p";
				   }
			   }
			   //if(i==1&&j==4) cout<<f[i][j];
		   }
	   }
	   int ans=0;
	   for(int i=1;i<=n;i++){
		   for(int j=i+1;j<=n;j++){
			   if(v[i][j]==2) ans++;
		   }
	   }
	   cout<<ans<<'\n';
   }
}
