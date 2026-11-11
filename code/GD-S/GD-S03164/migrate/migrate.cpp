#include<bits/stdc++.h> 
using namespace std;
long long a[2000010];
int dp[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//
	int c,t;cin>>c>>t;
	while(t--){
		int ans=0;
		memset(dp,0,sizeof(dp));
		int n,d;cin>>n>>d;
		for(int i=0;i<n;i++)cin>>a[i];
		if(a[n-1]-a[0]<d){cout<<0<<endl;continue;
		}
		for(int i=0;i<n;i++){
			int j=upper_bound(a,a+n,a[i]+d)-a;
			int num =i;
			for(j;j<n;j++){
				if(j-num+1==4)ans++;
				else if(j-num+1>4){
					num=j;
					j=upper_bound(a,a+n,a[j]+d)-a;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
