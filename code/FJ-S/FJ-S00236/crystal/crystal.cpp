#include<bits/stdc++.h>//dadadadada~haoxiangwanaizhichao~aizhichao!wuwuwuwuwu~haoxiangwanGAL~GALgame!
typedef long long ll;
using namespace std;
ll a[500005],ans[500005],usa[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	const ll mam=m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
//		cout<<i;
	}
	ll c=a[n]-a[n-1];
//	cout<<1<<endl;
	for(ll i=1;i<=n;i++){
		usa[i]=a[i];
	}
	sort(a+1,a+n+1);
	int aaa=1;
	for(ll i=1;i<=n;i++){
		if(a[i]!=usa[i])
			aaa+=1;
	}
	if(aaa==1){
		cout<<m/c+1;
		return 0;
	}
	for(ll i=n;i>=1;i--){
		ans[i]++;
		for(ll j=i-1;a[i]<=m+a[j] && j>=1;j--){
//			if() break;
			ans[i]++;
			m-=a[i]-a[j];
//			cout<<i<<' '<<j<<' '<<m<<' '<<a[i]-a[j]<<endl;
		}
		m=mam;
	}
	sort(ans+1,ans+n+1);
	cout<<ans[n];
	
	return 0;
}
