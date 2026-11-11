#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n,m;
ll num[500005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i <= n;i ++){
		cin>>num[i];
	}sort(num+1,num+1+n);
	ll l = 1,sum = 0,ans = 1;
	for(ll r = 2;r <= n;r ++){
		sum += 1LL*(r-l)*(num[r]-num[r-1]);
		while(sum > m){
			sum -= (num[r] - num[l]);
			l ++;
		}ans = max(ans,r-l+1);
	}cout<<ans;
	return 0;
}

