#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll arr[N],dp[N];
ll n,m;
bool check(){
	ll dc=arr[2]-arr[1];
	for(int i=3;i<=n;i++){
		if(arr[i]-arr[i-1]!=dc){
			return 0;
		}
	}
	return 1;
}
ll pd(ll x){
	ll ck=0,i=0;
	while(x>=ck){
		i++;
		ck+=i;
	}
	return i;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	if(check()){
		cout<<pd(m/(arr[2]-arr[1]));
		return 0;
	}
	ll ans=0;
	for(int i=2;i<=n;i++){
		ll sum=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			sum+=arr[i]-arr[j];
			if(sum>m){
				ans=max(ans,cnt);
				break;
			}
			cnt++;
			if(sum==m){
				ans=max(ans,cnt);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

