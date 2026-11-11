#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=500+5;
int c,T,n,d,x[N],dis[N][N],p[N]; 
#undef int 
/*
0 1
5 3
-3 0 2 3 4
*/
int main(){
#define int long long 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1e18;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]>d)break;
				dis[j][i]=1;
				p[i]=j;
			}
		}
		int ans=0;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<p[i];j++)dis[j][i]=dis
		}
		for(int l=3;l<=n;l++){
			for(int i=1;i<=n-l+1;i++){
				int j=i+l-1,ct=0;
				for(int k=i+1;k<j;k++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				for(int k=i+1;k<j;k++){
					ct+=(dis[i][j]==dis[i][k]+dis[k][j]);
				}
				if(ct==2)ans++;
			}
		}
//		cerr<<dis[1][4]<<'\n';
		cout<<ans<<'\n';
	}

	return 0;
}
