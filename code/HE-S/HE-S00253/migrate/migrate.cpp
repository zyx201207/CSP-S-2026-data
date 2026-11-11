#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c,t,n,lst[N],nxt[N],dp[N],a[N],mn[N];
int d,ans;
void solve(int s){
	mn[s] = 0;
	for(int i = s + 1;i <= n;i ++)mn[i] = mn[max(lst[i],s)] + 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c == 11 || c == 12){
		while(t --){
			cin >> n >> d;ans = 0;
			for(int i = 1;i <= n;i ++)cin >> a[i];
			if(n == 1){cout << "0\n";continue;}
			int cha = a[2] - a[1],ge = min(1ll * n,d / cha);
			if(ge <= 1){cout << "0\n";continue;}
			ge = ge * 2 - 1;
			for(int i = 1;i <= n;i ++){
				if(i + ge > n)break;
				ans ++;
			}
			cout << ans << '\n';
		}
	}
	else{
		while(t --){
			cin >> n >> d;ans = 0;
			for(int i = 1;i <= n;i ++)cin >> a[i];
			for(int i = 1,r = 1;i <= n;i ++){
				while(r < n && a[r + 1] - a[i] <= d)r ++;
				nxt[i] = r;
			}
			for(int i = n,l = n;i >= 1;i --){
				while(l > 1 && a[i] - a[l - 1] <= d)l --;
				lst[i] = l;
			}
			for(int l = 1;l <= n;l ++){
				solve(l);
				for(int i = 1;i <= n;i ++)dp[i] = 0;
				dp[l] = 1;int L = l,R = l - 1,sum = 0;
				for(int r = l + 1;r <= n;r ++){
					int lll = max(l,lst[r]);
					if(lll == r)break;
					while(L < lll)sum -= dp[L ++];
					while(R < L)sum += dp[++ R];
					while(R < r - 1 && (mn[R + 1] == mn[r] - 1))sum += dp[++ R];
					dp[r] += sum;
					if(dp[r] == 2)ans ++;
//					cout << l << ' ' << r << ' ' << dp[r] << '\n';
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
