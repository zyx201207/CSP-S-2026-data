#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,dp[10005][10005];
string v="",b="",c="";

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll a; char s;
		cin>>a>>s;
		while(a--){
			v+=s;
		}
	}
	ll l=v.size()/2,k=v.size();
	for(ll i=1;i<=l;i++){
		b+=v[i-1];
		c+=v[k-i];
	}
	ll g=b.size(),h=c.size();
	for(int i=0;i<g;i++){
		for(int j=0;j<h;j++){
			if(b[i]==c[j]) dp[i+1][j+1]=dp[i][j]+1;
			else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		}
	}
	cout<<l-dp[g][h]<<"\n";
	return 0;
}
