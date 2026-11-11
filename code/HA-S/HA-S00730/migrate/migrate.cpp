#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,c,t;
ll a[500005],dis[10001][10001],k[500005],x[500005],ans[10001][10001];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) dis[i][j]=0;
				else dis[i][j]=0x3FFFFFFF;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					dis[i][j]=abs(x[i]-x[j]);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
//			}
//		}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(dis[i][j]==dis[i][k]+dis[k][j]&&dis[i][j]!=0x3FFFFFFF&&j-i>=3)
					ans[i][j]++;
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	ll num=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(ans[i][j]==2){
					num++;
				}
			}
		}
	cout<<num<<"\n";
}
	return 0;
}
