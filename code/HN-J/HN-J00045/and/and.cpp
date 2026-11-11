#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	
	vector<ll> dp(N,0);
	vector<ll> v(N);
	ll ma=0;
	for(ll i=1;i<=n;i++){
		cin>>v[i];
		dp[i]=v[i];
		dp[i+n]=v[i];
		ma=max(ma,v[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	for(ll i=2;i<=m;i++){
		ll res=dp[i-1];
		dp[i]=res & dp[i];
		for(ll j=i+1;j<=n*2;j++){
			ll d1=res & dp[j];
			ll d2=dp[j-1];
			res=dp[j];
			dp[j]=max(d1,d2);
			//cout<<dp[j]<<" ";
		}
		//for(int j=1;j<=n;j++)cout<<dp[j]<<" ";
		//cout<<endl;
	}
	cout<<dp[n*2];
	//5 3 31 3 1 15 7
	return 0;
}
