#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	vector<ll> a(n+1);
	
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a.begin()+1,a.end());
	
	for(int i=1;i<n;i++){
		a[i]=a[i+1]-a[i];
	}
	
	vector<int> dp(m+1,0);
	
	for(int i=1;i<n;i++){
		for(ll j=m;j>=a[i];j--){
			dp[j]=dp[j-a[i]]+1;
		}
	}

	cout<<dp[m]+1;
	
	return 0;
}
