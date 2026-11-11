#include <bits/stdc++.h>
using namespace std;
long long c,t,n,m,x[2000005],d[2000005],dp[2000005],ans;
bool flag_b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int op=1;op<=t;op++){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(x[i]+m>=x[j]) dp[j]=1;
				else{
					int minn=1e9+1,cnt=0;
					for(int l=j-m;l<j;l++){
						if(minn>dp[l]&&x[l]+m>=x[j]){
							minn=dp[l];
							cnt=1;
							continue;
						}
						if(minn==dp[l]&&x[l]+m>=x[j]) {
							cnt++;
						}
					}
					if(cnt==2)ans++;
					dp[j]=minn+1;	
				}
				
			}
		}
		cout<<ans;
	}
	return 0;
}
