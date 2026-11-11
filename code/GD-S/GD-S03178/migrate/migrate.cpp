#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 5005;
ll c,t,n,d;
ll a[MAXN],dp[5005][5005];
bool mp[MAXN][MAXN];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		memset(dp,0,sizeof(dp));
		memset(mp,0,sizeof(mp));
		ll num=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<i; j++) {
				if(a[i]-a[j]<=d) {
					mp[i][j]=1;
					mp[j][i]=1;
				}
			}
		}
		for(int qd=1; qd<n; qd++) {
			if(!mp[qd][qd+1])continue;
			dp[qd][qd+1]=1;
			for(int i=qd+1; i<=n; i++) {
				for(int j=i-1; j>qd; j--) {
					if(!mp[i][j])break;
					dp[qd][i]+=dp[qd][j];
				}
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<i; j++) {
				if(dp[j][i]==2) {
					//cout<<i<<' '<<j<<endl;
					num++;
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
