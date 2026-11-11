#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int c,t,n,d;
int a[maxn],dp[maxn];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
//			cout<<"i="<<i<<":\n";
			for(int j=i+1;j<=n;j++){
//				cout<<" j="<<j<<":\n";
				memset(dp,0x3f,sizeof(dp));
				dp[i]=1;
				int cnt=1;
				for(int k=i;k<=j;k++){
					for(int l=k+1;l<=j;l++){
						if(a[l]-a[k]>d)break;
						if(l==j){
							if(dp[l]>dp[k]+1)cnt=1;
							if(dp[l]==dp[k]+1)cnt++;
						}
						dp[l]=min(dp[l],dp[k]+1);
//						cout<<"  "<<k<<"->"<<l<<" "<<dp[l]<<"\n";
					}
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
