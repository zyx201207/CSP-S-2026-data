#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
typedef long long ll;
const int N=2e6+5;
ll read(){
	ll x=0; bool f=1;
	char c=gc();
	while(c>'9'||c<'0'){
		if(c=='-') f=0;
		c=gc();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=gc();
	}
	return f?x:-x;
}
void put(ll x){
	if(x<0){x=-x;pc('-');}
	if(x>9)put(x/10);
	pc(x%10+'0');
}
ll x[N],n,d;
ll dp[N],cnt[N];
ll find(ll j){
	return lower_bound(x+1,x+1+n,x[j]-d)-x;
}
void solve(){
	n=read();d=read();
	for(int i=1;i<=n;++i) x[i]=read();
	ll ans=0;
	for(ll s=1;s<n;++s){
		cnt[s-1]=dp[s]=0;
		cnt[s]=1;
		ll st=s;
		for(int i=s+1;i<=n;++i){
			int j=max(s,find(i));
			dp[i]=dp[j]+1;
			if(dp[i]>dp[i-1]) st=i;
			cnt[i]=cnt[st-1]-cnt[j-1];
			ans+=(cnt[i]==2);
			cnt[i]+=cnt[i-1];
		}
	}
	put(ans);pc('\n');
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c=read(),T=read();
	while(T--)solve();
	return 0;
}

