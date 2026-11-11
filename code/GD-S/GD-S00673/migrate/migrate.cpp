#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N=2e6+5;
ll c,t,n,d,a[N],dp[N],cnt,mi=2e6+5,nmi=2e6+5,ans=2e6+5;
deque<pair<ll,ll>> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(ll i = 1;i<=n;i++){
			scanf("%lld",&a[i]);
			dp[i]=0;
		}
		for(ll i = 1;i<=n;i++){
			++cnt;
			for(ll j = i;j<=d&&i+j<=n;j++){
				q.push_back({i+j,cnt});
			}
		}
		while(!q.empty()){
			q.front();
			if(q.front().first == a[n] && q.front().second<mi){
				ans=1;
				mi=q.front().second;
			}else if(q.front().first==a[n]&&q.front().second==mi) ans++;
			q.pop_front();
			for(ll j = q.front().first;j<=d&&q.front().first+j<=n;j++){
				q.push_back({q.front().first+j,q.front().second+1});
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
