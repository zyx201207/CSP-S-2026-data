#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[2100000];
int dp[2100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;int id,mi,ans;
	while(t>0){
		t--;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i]=0;
		}
		ans=0;
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++){
				dp[i]=0;
			}
			for(int i=l;i<=n;i++){
				if(a[i]-a[l]<=d){dp[i]=1;continue;}
				mi=1e9;
				id=lower_bound(a+l,a+i+1,a[i]-d)-a;
				for(int j=id;j<i;j++){
					if(dp[j]+1<mi){
						mi=dp[j]+1;
						dp[i]=1;
					}
					else if(dp[j]+1==mi){
						dp[i]++;
					}
				}if(dp[i]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
