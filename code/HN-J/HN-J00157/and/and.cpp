#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N=2e5+5;
ll n,m,a[N];
bool s[35][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)s[31][i]=1;
	for(ll i=30;i>=0;i--){
		ll sum=0;
		for(ll j=1;j<=n;j++){
			s[i][j]=s[i+1][j];
		}
		for(ll j=1;j<=n;j++){
			if(!s[i][j])continue;
			if(((a[j]>>i)&1)==1)sum++;
		}
		if(sum<m)continue;
		for(ll j=1;j<=n;j++){
			if(!s[i][j])continue;
			if(((a[j]>>i)&1)==0)s[i][j]=0;
		}
	}
	ll ans=2147483647;
	for(ll i=0;i<=31;i++){
		ll sum=0;
		for(ll j=1;j<=n;j++)
			if(s[i][j])sum++;
		if(sum>=m){
			ll x=0;
			for(ll j=1;j<=n;j++){
				if(s[i][j])ans&=a[j],x++;
				if(x==m)break;
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
