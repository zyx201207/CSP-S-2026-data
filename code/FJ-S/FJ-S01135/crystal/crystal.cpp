#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,m,a[500005],sum[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	ll bj=0;
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(a[i]*(i-bj)-(sum[i]-sum[bj])<=m){
			ans=max(ans,(i-bj));
		}else{
			bj++;
		}
	}
	cout<<ans;
	return 0;
}
