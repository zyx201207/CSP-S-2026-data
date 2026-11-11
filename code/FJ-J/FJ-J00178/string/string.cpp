#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
int n;
char c[N];
ll sum[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> sum[i] >> c[i],sum[i]+=sum[i-1];
	ll la=n,lan=sum[n];
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll x=sum[i-1];
		if(x>=lan) break; 
		while(x+(lan-sum[la-1])<=sum[i]&&x<lan&&la>0) x+=(lan-sum[la-1]),ans+=(c[i]==c[la]?0:(lan-sum[la-1])),la--,lan=sum[la];
		if(c[i]!=c[la]&&x<lan) ans+=sum[i]-x;
		lan-=(sum[i]-x);
	}
	cout << ans;
	return 0;
}
