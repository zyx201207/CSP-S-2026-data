#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	ll m2=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		m=m2;
		for(int j=1;j<=i;j++){
			m=m-(a[i]-a[j]);
		}
		if(m<0){
			ans=i-1;
			break;
		}
	}
	if(ans==0){
		cout<<n-1;
		return 0;
	}
	cout<<ans;
	return 0;
}
