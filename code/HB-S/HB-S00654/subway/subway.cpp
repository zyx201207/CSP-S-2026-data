#include<bits/stdc++.h>
using namespace std;
const int N=1005;
long long w[N],k[N],a[N][505],t[N][505],ff[505][505],w1[500005],f1[500005][2],f2[500005][2];
int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
   int c,n,m,d,q;
   cin>>c>>n>>m>>d>>q;
   for(int i=1;i<=m;i++){
	   cin>>w[i];
   }
   memset(ff,0x3f,sizeof(ff));
   for(int i=1;i<=n;i++){
	   cin>>k[i];
	   for(int j=1;j<=k[i];j++){
		   cin>>a[j][i]>>t[j][i];
		   for(int l=1;l<j;l++){
			   int p1=a[l][i],p2=a[j][i];
			   ff[p1][p2]=min(ff[p1][p2],t[j][i]+t[l][i]);
			   ff[p2][p1]=min(ff[p1][p2],t[j][i]+t[l][i]);
			   //cout<<ff[p1][p2]<<" "<<p1<<" "<<p2<<"\n";
		   }
	   }
   }
   for(int l=1;l<=m;l++){
	   for(int i=1;i<=m;i++){
		   if(i==l) continue;
		   for(int j=1;j<=m;j++){
			   if(j==i||j==l) continue;
			   ff[i][j]=min(ff[i][j],ff[i][l]+ff[j][l]);
			   ff[j][i]=min(ff[i][j],ff[i][l]+ff[j][l]);
		   }
	   }
   }
   while(q--){
	   int x,y;
	   cin>>x>>y;
	   cout<<w[x]+w[y]+ff[x][y]<<"\n";
   }
}
