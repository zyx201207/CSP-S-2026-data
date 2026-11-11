#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5005;
ll c,t,n,d,x[N],k[N],dp[N][N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(dp,0,sizeof(dp));
		cin>>n>>d;
		k[1]=1;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
			if(i!=1) k[i]=lower_bound(x+1,x+i,x[i]-d)-x;
		}
		for(ll i=1;i<n;i++){
			dp[i][i]=1;
			for(ll j=i+1;j<=n;j++){
				if(k[j]<=i){
					dp[i][j]=1;
					continue;
				}
				ll o=1e18,js=0;
				for(ll z=k[j];z<j;z++) o=min(o,dp[i][z]);
				for(ll z=k[j];z<j;z++) if(dp[i][z]==o) js++;
				if(js==2) ans++;
				dp[i][j]=o+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
