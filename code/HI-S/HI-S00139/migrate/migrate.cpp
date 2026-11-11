#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
typedef long long ll;
ll d,n;
ll x[N],dis[N][N],cnt[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dis,0x3f,sizeof dis);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++) cin>>x[i];
	    int sum=0;
	   for(int i=1;i<=n;i++){
	   	    dis[i][i]=0;
	   	    for(int j=i;j<=n;j++){
	   	  		for(int k1=i;k1<j;k1++){
	   	  	  		if(x[j]-x[k1]<=d){
	   	  	 		dis[i][j]=min(dis[i][j],dis[i][k1]+1);
				} }}}
		
		for(int k=1;k<=n;k++){
		for(int i=1;i<=k-1;i++){
			for(int j=k+1;j<=n;j++){
				if(dis[i][k]<=1e18+10&&dis[k][j]<=1e18+10){
				if(dis[i][j]==dis[i][k]+dis[k][j]) cnt[i][j]++;}
			}
		}}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2) {
				sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0; 
}
