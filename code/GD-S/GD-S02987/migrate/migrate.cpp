#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t;
int n,d,x[N];
ll dp[N],cnt[5005][5005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> c >> t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		cin >> n >> d;
		for(int i=1; i<=n; i++){
			cin >> x[i];
		}
		for(int i=1; i<=n; i++){
			memset(dp,63,sizeof(dp));
			dp[i]=0;
			for(int j=i; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(x[k]-x[j]<=d){
						if(dp[j]+1<dp[k]){
							cnt[j][k]=1;
							dp[k]=dp[j]+1;
						}
						else if(dp[j]+1==dp[k]){
							cnt[j][k]++;
						}
					}
				}
			}
			for(int j=i; j<=n; j++){
				for(int k=j+1; k<=n; k++){
					if(cnt[j][k]==2) ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
