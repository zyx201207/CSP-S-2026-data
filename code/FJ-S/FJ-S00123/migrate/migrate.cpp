#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,T;
ll n,d;
vector<ll> a;
vector<ll> dp;
vector<ll> g;
deque<pair<ll,ll> > q;
ll cnt;
ll read(){
	ll sum=0;
	ll t=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-'){
			t=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum*t;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(); 
	T=read();
	while(T--){
		n=read();
		d=read();
		cnt=0;
		vector<ll> a(n+1,0);
		for(ll i = 1;i<=n;i++){
			a[i]=read();
		}
		for(ll k = 1;k<=n;k++){
			vector<ll> dp(n+1,INT_MAX);
			vector<ll> g(n+1,0);
			g[k]=1; 
			dp[k]=0;
			for(ll i = k;i<=n;i++){
				for(ll j = i-1;j>=k;j--){
					if(a[i]-a[j]>d){
						break;
					}
					if(dp[i]>dp[j]+1){
						dp[i]=dp[j]+1;
						g[i]=g[j];
					}
					else if(dp[i]==dp[j]+1){
						g[i]+=g[j];
					}
				}
				if(g[i]==2){
					cnt++;
				}
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
