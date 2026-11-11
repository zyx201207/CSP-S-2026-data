#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1e8+10;
ll n,m; 
ll zhi[MAX_N],cha[MAX_N];
ll pre(ll b){
	ll ans = 0; 
	for(ll i = 1; i <= b; i++){
		ans += cha[i];
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1; i <= n; i++){
		cin>>zhi[i];
	}
	ll mid;
	if(n % 2 == 0){
		mid = n/2;
	}
	else{
		mid = n/2 + 1;
	}
	sort(zhi+1,zhi+n+1);
	for(ll i = 1; i <= n; i++){
		if(i == mid){
			cha[i] = 0;
		}
		else if(i < mid){
			cha[i] = zhi[mid] - zhi[i];
		}
		else{
			cha[i] = zhi[i] - zhi[mid];
		}
	};
	sort(cha+1,cha+n+1);
	for(ll i = 1; i <= n; i++){
		if(pre(i) < m){
			continue; 
		}
		else if(pre(i) == m){
			cout<<i;
			return 0;
		}
		else{
			cout<<i - 1;
			cout<<pre(i-1);
			return 0;
		}
	}
	return 0;
}
