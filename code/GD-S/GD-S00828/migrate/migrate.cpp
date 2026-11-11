#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lc(i) ((i)<<1)
#define rc(i) ((i)<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
constexpr int N=2e6+5;
constexpr int Mod=1e9+9;
int caseID;
int n;
ll m,x[N];
int dp[N],cnt[N];
void solve(){
	cin>>n>>m;
//	cerr<<"n = "<<n<<", m = "<<m<<'\n';
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	ll ans=0;
	for(int s=1;s<=n;s++){
//		cerr<<"s = "<<s<<'\n';
		cnt[s]=1;
		dp[s]=0;
		for(int i=s+1;i<=n;i++){
//			cerr<<"i = "<<i<<'\n';
			dp[i]=0x7f7f7f7f;
			cnt[i]=0;
			for(int j=i-1;j>=s;j--){
				if(x[i]-x[j]>m)break;
				if(dp[j]+1<dp[i]){
					dp[i]=dp[j]+1;
					cnt[i]=cnt[j];
				}else if(dp[j]+1==dp[i]){
					cnt[i]=(cnt[i]+cnt[j])%Mod;
				}
			}
			if(cnt[i]==2){
				ans++;
			}
//			cerr<<"dp["<<i<<"] = "<<dp[i]<<" cnt["<<i<<"] = "<<cnt[i]<<'\n';
		}
//		cerr<<'\n';
	}
//	cerr<<"ans = "<<ans<<'\n';
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>caseID;
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
/*
路径不会迂回
即 y_1<y_2<...<y_m 

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
