#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+100;
int c,t;
int n,d;
int a[N];
int dp[N];
int num[N];
int ans;


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=6){
		while(t--){//duoce
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				memset(dp,0x3f,sizeof dp);
				memset(num,0,sizeof num);
				dp[i]=0;
				num[i]=1;
				for(int j=i+1;j<=n;j++){
					for(int l=j-1;l>=i;l--){
						if(a[j]-a[l]>d)break;
						if(dp[j]>dp[l]+1){
							dp[j]=dp[l]+1;
							num[j]=num[l];
						}else if(dp[j]==dp[l]+1){
							num[j]+=num[l];
						}
					}
					if(num[j]==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}else if(c>=11&&c<=12){
		while(t--){//duoce
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(n==1){
				cout<<0<<'\n';
				continue;
			}
			int gc=a[2]-a[1];
			int jump=d/gc;
			if(jump==0){
				cout<<0<<'\n';
				continue;
			}
			for(int i=1;i<n-jump;i++){
				ans+= (bool)((n-i-jump)%jump)==(jump-1);
				ans+=( (n-i-jump)/jump );
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
