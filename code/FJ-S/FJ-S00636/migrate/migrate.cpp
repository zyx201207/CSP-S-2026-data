#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d;
int a[N];
int dp[N],f[N];
int dl[N],lt,rt;
int ans;
void sovle(){
	ans=0;
	cin >> n >> d;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j)dp[j]=n,f[j]=0;
		f[i]=1,dp[i]=0;
		for(int j=i+1;j<=n;++j){
			if(a[j]-a[j-1]>d)break;
			for(int k=i;k<=j-1;++k){
				if(a[j]-a[k]<=d){
					if(dp[j]>dp[k]+1){
						dp[j]=dp[k]+1;f[j]=f[k];
					}else if(dp[j]==dp[k]+1)f[j]=f[j]+f[k];
					else break;
				}
			}
			if(f[j]==2)ans++;
			if(f[j]>2)break;
		}
	}
	cout << ans << '\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin >> c >> T;
	while(T--)sovle();
	return 0;
}
