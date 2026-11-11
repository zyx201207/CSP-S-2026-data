#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[300009],a[500009],dz[300009],ans[300009];
int dx[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int uj=0;
	for(int u=1;u<=n;u++){
		uj=1;
		memset(dx,0,sizeof(dx));
		for(int i=u;i<=n;i++){
			dx[a[i]]++;
			if(dx[a[i]]>1){
				for(int io=dz[a[i]];io<uj;io++){
					dx[dp[io]]=0;
				}
				uj=dz[a[i]];
				dx[a[i]]=1;
			}
			dz[a[i]]=uj;
			dp[uj]=a[i];
			uj++;
		}
		for(int i=1;i<uj;i++){
			for(int io=1;io<=m;io++){
				if(dp[i]==io){
					ans[io]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
