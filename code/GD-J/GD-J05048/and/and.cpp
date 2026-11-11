#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<ll> nums(n+5);
	for(int i=0;i<n;++i){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end(),greater<ll>());
	if(m==1){
		cout<<nums[0];
		return 0;
	}
	if(n==m){
		ll a=nums[0];
		for(int i=1;i<n;++i){
			a&=nums[i];
		}
		cout<<a;
		return 0;
	}
	if(m==2){
		ll maxn=0;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				ll a=nums[i]&nums[j];
				maxn=max(maxn,a);
			}
		}
		cout<<maxn;
		return 0;
	}
	ll a=nums[0];
	for(int i=1;i<m;++i){
		a&=nums[i];
	}
	cout<<a;
	return 0;
}
