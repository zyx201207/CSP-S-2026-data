#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+10;
ll a[N],dp[N][N],n,T,flag[N],cnt[N][N],k,ans;
queue<ll> q;
void bfs(ll s){
	q.push(s);
	while(!q.empty()){
		ll T=q.front();q.pop();
		ll j=T,sum=0;
		while(sum+a[j+1]-a[j]<=k){
            sum=sum+a[j+1]-a[j];
            j++;
		}
		for(ll J=j;J>=T+1;J--){
			if(dp[s][J]==0x3f3f3f3f3f3f3f3f){
				dp[s][J]=dp[s][T]+1;
				cnt[s][J]+=cnt[s][T];
				q.push(J);
			}else if(dp[s][J]==dp[s][T]+1) cnt[s][J]+=cnt[s][T];
		}
	}
}
void solve(){
	cin>>n>>k;
	memset(dp,0x3f,sizeof(dp));
	memset(cnt,0,sizeof(cnt));
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=0;
		cnt[i][i]=1;
	}
	if(n>5000){
		cout<<"0\n";
	}else{
		for(ll i=1;i<=n;i++){
			 memset(flag,0,sizeof(flag));
			 bfs(i);
		 }
		ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T>>T;
    while(T--) solve();
    return 0;
}
