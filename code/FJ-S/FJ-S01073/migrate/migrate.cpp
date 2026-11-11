#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000006],w[5005][5005],dp[5005][5005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int last=i,y=0,k;
				for(k=i+1;k<=j;k++){
					if(x[k]-x[last]>d) y++,last=k-1;
				}
				if(k!=j) y++;
				w[i][j]=k;
			}
		}
		for(int i=1;i<n;i++) dp[i][i+1]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j+i<=n;j++){
				for(int k=i+j-1;x[i+j]-x[k]<=d && k>=1;k--){//cout<<k<<" ";
					if(w[j][k]==w[j][j+i]-1) dp[j][i+j]+=dp[j][k];
				}//cout<<"\n";
				if(dp[j][i+j]==2) ans++;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				cout<<w[i][j]<<" ";
//			}cout<<"\n";
//		}
		cout<<ans<<"\n";
	}
}
/*
0 1
5 3
-2 -1 0 1 2
*/