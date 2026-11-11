#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;
#define int long long

int c;
int n;
int d;
int x[2000020];
int nemax[2000020];
pair<int,int> dp[5050][5050];

void do_it(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	nemax[0]=1;
	for(int i=1;i<=n;i++){
		nemax[i]=max(nemax[i-1],i);
		while(nemax[i]<=n && x[nemax[i]]<=x[i]+d)
			nemax[i]++;
		nemax[i]--;
	}
	if(c<=10){
		for(int i=n;i>=1;i--){
			dp[i][i]=make_pair(0LL,1LL);
			for(int j=i+1;j<=n;j++){
				dp[i][j]=make_pair(0x3f3f3f3fLL,1);
				for(int k=i;k<=min(j,nemax[i]);k++){
					if(dp[k][j].first+1<dp[i][j].first){
						dp[i][j]=dp[k][j];
						dp[i][j].first++;
					}
					else if(dp[k][j].first+1==dp[i][j].first){
						dp[i][j].second=
						min(dp[i][j].second+dp[k][j].second,10LL);
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ans+=(dp[i][j].second==2 && dp[i][j].first<=10000000);
				//cerr<<i<<' '<<j<<"dp:"<<endl;
				//cerr<<dp[i][j].first<<' '<<dp[i][j].second<<endl;
			}
		}
		cout<<ans<<endl;
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		do_it();
	}
	return 0;
}
