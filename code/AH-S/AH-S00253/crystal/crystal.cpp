#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
inline ll read(){
	ll x=0,f=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=gc();
	}
	return x*f;
}
const int N=5e5+10;
ll n,m,a[N],dp[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n,[](ll a,ll b){
		return a>b;
	});
	ll ans=-1e18;
	for(ll i=1;i<=n;i++){
		if(n-i+1<=ans){
			break;
		}
		ll sum=0,can=0;
		for(ll j=i;j<=n;j++){
			if(sum+a[i]-a[j]<=m){
				sum+=(a[i]-a[j]);
				can++;
			}
		}
		ans=max(ans,can);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
 * 
 * 
 */
