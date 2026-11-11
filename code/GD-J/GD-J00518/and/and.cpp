#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,cnt[31],ans,a[20005];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(ll i=30;i>=0;i--){
			if((1<<i)&a[i])cnt[i]++;
		}
	}
	for(ll i=30;i>=0;i--){
		if(cnt[i]>=2){
		ans=ans+(1<<i);
		}
	}
	cout<<ans;
	return 0;
}

