#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200005;
ll n,m,a[N],num[N][35],maxx,ans,cnt[35],Get[N],cntt;
queue<ll> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++){
		Get[++cntt]=i;
		ll x=a[i];
		while(x>0){
			num[i][++num[i][0]]=x%2;
			if(x%2) ++cnt[num[i][0]];
			x/=2;
		}
		maxx=max(maxx,num[i][0]);
	}
	for(ll i=maxx;i>=1;i--){
		ans*=2;
		if(cnt[i]<m) continue;
		else{
			memset(cnt,0,sizeof(cnt));
			++ans;
			for(ll j=1;j<=cntt;j++){
				ll u=Get[j];
				if(num[u][i]) q.push(u);
			}
			cntt=0;
			while(!q.empty()){
				ll u=q.front();
				Get[++cntt]=u;
				for(ll j=1;j<i;j++) cnt[j]+=num[u][j];
				q.pop();
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
