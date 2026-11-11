#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c=0;
	ll t=0;
	cin>>c>>t;
	vector<ll> n(t,0),d(t,0);
	vector<vector<ll>> x(t);
	vector<ll> dp;
	int cnt=0;
	for(ll i=0;i<t;i++) {
		cnt=0;
		cin>>n[i]>>d[i];
		x[i].resize(n[i]);
		for(int k=0;k<n[i];k++) cin>>x[i][k];
		dp.resize(n[i]);
		dp[0]=1;
		if(c==11 || c==12) {
			if(x[i][1]-x[i][0]>d[i]) cnt=0;
			else if(x[i][1]-x[i][0]==d[i]) cnt=0;
			else for(ll k=1;k<n[i];k++) {
				if(x[i][k]%d[i]==0) dp[k]=1;
				else dp[k]=(x[i][k]/d[i])+1;
				if(dp[k]==2) cnt++;
			}
		} else if(c==13 || c==14) {
			if(x[i][1]-x[i][0]>d[i]) cnt=0;
			else if(x[i][1]-x[i][0]==d[i]) cnt=0;
			else for(ll k=1;k<n[i];k++) {
				if(x[i][k]-x[i][0]>d[i])  {
					cnt=0;
					break;
				}
				if(x[i][k]%d[i]==0) dp[k]=1;
				else dp[k]=(x[i][k]/d[i])+1;
				if(dp[k]==2) cnt++;
			}
			cnt++;
		} else if(c==15 || c==16 || c==17 || c==18) {
			if(x[i][1]-x[i][0]>d[i]) cnt=0;
			else if(x[i][1]-x[i][0]==d[i]) cnt=0;
			else for(ll k=1;k<n[i];k++) {
				if(x[i][k]-x[i][k-1]>d[i]) {
					cnt=0;
					break;
				}
				if(x[i][k]%d[i]>=0) dp[k]=1;
				else dp[k]=(x[i][k]/d[i])+1;
				if(dp[k]==2) cnt++;
			}
		} else {
			for(ll k=1;k<n[i];k++) {
				int index=0;// island index 
				if(k>d[i]) index=k-d[i];
				if(x[i][k]-x[i][index]>d[i]) {
					cout<<cnt;
					break;
				} else if(x[i][k]-x[i][index]==d[i]) dp[k]=1;
				else {
					if(k<d[i]) dp[k]=1;
					else if((x[i][k]-1)%d[i]==0) dp[k]=1;
					else dp[k]+=(dp[index]+(x[i][k]/d[i])+1);
				}
				
				if(dp[k]>=1) cnt++;
			}
			cnt-=2;
		}
		cout<<cnt<<"\n";
	} 
	
	return 0;
}
