#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	vector<int> island;
	cin>>c>>t;
	while(t--) {
		int ans=0;
		cin>>n>>d;
		island.resize(n);
		for(int i=0; i<n; i++) cin>>island[i];
		for(int st=0; st<n; st++) {
			vector<int> dp;
			dp.resize(n-st,0x3ffffff);
			dp[0]=0;
			for(int i=1; i<n-st; i++) {
				for(int j=0; j<i; j++) {
					if(island[st+i]-island[st+j]<=d) {
						dp[i]=min(dp[i],dp[j]+1);
					}
				}
				for(int j=0; j<i; j++) {
					if(island[st+i]-island[st+j]<=d && dp[j]+1==dp[i]) {
						ans++;
					}
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
