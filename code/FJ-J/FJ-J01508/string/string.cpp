#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool huiwen(string a){
	ll l=a.size();
	ll b=0;
	for(int i=0;i<l;i++){
		if(a[i]==a[l-i-1]) b++;
	}
	return b==l;
}
void change(string a,vector<ll> &dp,ll now){
	if(now==a.size()/2+1) return;
	ll num=0;
	for(int i=now;i<a.size();i++){
		if(huiwen(a)) break;
		if(a[i]!=a[a.size()-i-1]){
			num++;
			a[i]==a[a.size()-i-1];
		}
	}
	dp[now]=min(num,dp[now-1]);
	change(a,dp,now+1);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll j;
		char c;
		cin>>j>>c;
		for(ll k=0;k<j;k++) S+=c;
	}
	vector<ll> dp(S.size()+2);
	dp={0};
	change(S,dp,0);
	cout<<dp[S.size()-1];
	return 0;
}
