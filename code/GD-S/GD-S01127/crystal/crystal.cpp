#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,m;
ll s[N],pre[N];
bool check(ll num){
	ll tmp=1e18+10;
	for(int i=num;i<=n;i++){
		tmp=min(tmp,s[i]*num-pre[i]+pre[i-num]);
		if(tmp<=m)return true;
	}
	if(tmp<=m)return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+s[i];
	}
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	cout<<r-1;
	return 0;
}
