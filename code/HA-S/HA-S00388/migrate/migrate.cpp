#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d,x[5005],cnt[5005],dp[5005],ans;
int main(){
	cin>>c>>t;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			memset(cnt,0,sizeof(cnt));
			memset(dp,0,sizeof(dp));
			for(int j=i;j<=i+d;j++){
				dp[j]=1;
				cnt[j]=1;
			}
			for(int j=i+d+1;j<=n;j++){
				for(int k=i+1;k<=j-1;k++){
					cnt[j]++;
				}
			}
			for(int j=i;j<=n;j++){
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	
}

