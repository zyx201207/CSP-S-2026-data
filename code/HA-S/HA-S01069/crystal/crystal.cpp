#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll s;
ll a[500010];
bool solve(ll x){
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(x-a[i]>0) sum+=x-a[i];
	}
	return sum<=m;
} 
ll bin(){
	ll low=1,high=1e12;
	ll ans=0;
	while(low<=high){
		ll mid=(low+high)/2;
		if(solve(mid)){
			low=mid+1;
			ans=mid;
		}else{
			high=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll aa=bin();
	for(int i=1;i<=n;i++){
		if(a[i]<=aa){
			s++;
		}
	} 
	cout<<s;
}
