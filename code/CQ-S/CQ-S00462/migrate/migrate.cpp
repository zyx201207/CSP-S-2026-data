#include<bits/stdc++.h>
#define N 2000006
#define ll long long
using namespace std;
int c,T,n,r[N];
ll x[N],qz[5005][5005],d,dp[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		cin>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=2){
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12){
			ll f=d/(x[2]-x[1]),ans=0;
			if(f<=1){
				cout<<"0\n";
				continue;
			}
			cout<<max(0ll,n-2*f+1)<<"\n";
			continue;
		}
		for(int i=n,j=n;i>=1;i--){
			while(x[j]-x[i]>d) j--;
			r[i]=j;
		}
		if(c<=6){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					for(int k=0;k<=n;k++) dp[j][k]=0;
				}
				dp[i][0]=1;
				for(int j=i;j<=n;j++){
					int mi=-1;
					if(j>i){
						for(int k=1;k<=n;k++){
							dp[j][k]+=dp[j-1][k];
							if(dp[j][k]>0&&mi==-1){
								mi=k;
							}
						}
					}
					if(j==i) mi=0;
					if(dp[j][mi]==2){
						ans++;
					}
					dp[j+1][mi+1]+=dp[j][mi];
					dp[r[j]+1][mi+1]-=dp[j][mi];
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}/*
1~6
11
12

*/
