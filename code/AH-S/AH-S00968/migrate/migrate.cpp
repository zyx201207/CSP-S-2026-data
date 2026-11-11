#include<bits/stdc++.h>
#define rep(i,s1,s2,s3) for(i = s1;i <= s2;i += s3)
#define r(i,s1,s2,s3) for(i = s1;i >= s2;i -= s3)
#define ull unsigned ll
#define ll long long
using namespace std;
ll c,n,d,ans,x[2000010],f[2000010],dp[2000010];
deque <ll> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll i,j,k,l,r,t,sum,dis;
	cin>>c>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n>>d;
		ans = 0;
		rep(i,1,n,1) cin>>x[i];
		if(c < 11){
		 	rep(i,1,n,1){
				memset(dp,0,sizeof(dp));
				dp[i] = 1;
				q = deque <ll> ();
				q.push_back(i);
				rep(j,i + 1,n,1){
					while(q.size() && x[j] - x[q.front()] > d) q.pop_front();
					if(!q.size()) break;
	//				cout<<j<<' '<<q.front()<<' '<<dp[q.front()]<<'\n';
					dp[j] = dp[q.front()] + 1;
					while(q.size() && dp[q.back()] >= dp[j]) q.pop_back();
					q.push_back(j);
				}
	//			rep(k,i,n,1) cout<<dp[k]<<'\n';
				l = r = i;
				f[i] = 1;
				sum = 1;
				rep(k,i + 1,j - 1,1){
					while(dp[r + 1] < dp[k] || x[k] - x[r] > d) sum += f[++r];
					while(dp[l] + 1 < dp[k] || x[k] - x[l] > d) sum -= f[l++];
					f[k] = sum;
					ans += (f[k] == 2);
	//				cout<<i<<' '<<k<<' '<<l<<' '<<r<<'\n';
				}
			}
		}else if(10 < c){
			dis = x[2] - x[1];
			if(2 * dis > d) ans = 0;
			else ans = max(0ll,n + 1 - 2 * (d / dis));
		}
		cout<<ans<<'\n';
	}
	return 0;
}

