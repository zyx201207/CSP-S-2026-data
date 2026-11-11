#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	/*
	5 5
	1 2 4 8 9
	5 8
	-3 -1 2 2 7

	for(int i=1;i<=n;i++){
		cout<<ve[i];
	}
	*/
	ll n,m;
	scanf("%lld%lld",&n,&m);
	vector<ll>ve(n+1);
	vector<ll>lis(n+1);
	for(int i=1;i<=n;i++){
		ll a;
		scanf("%lld",&a);
		lis[i] = a;
		
	}
	sort(lis.begin(),lis.end());
	
	for(int i=1;i<=n;i++){
		ve[i] = lis[i] + ve[i-1];
	}

	ll max_=LLONG_MIN;
	ll l=1,r=1;
	ll h = 0,d =0;
	while(r<=n && l<=n){
		h = lis[r]*(r-l+1);
		d = ve[r] - ve[l-1];
		if(h-d<=m){
			max_ = max(max_,r-l+1);
			r++;		
		}else{
			l++;
		}
		
		//cout<<h<<" "<<d<<" "<<l<<" "<<r<<" "<<max_<<'\n';
	}
	printf("%lld",max_);
	return 0;
}
