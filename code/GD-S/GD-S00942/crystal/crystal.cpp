#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	int ok1=1,ok2=1;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]!=i) ok1=0;	
	}
	ll check=a[2]-a[1];
	for (int i=2;i<=n;i++){
		if (a[i]-a[i-1]!=check) ok2=0;
	}
	ll ans=1;
	if (ok2==1){
		for (int i=n-1;i>=1;i--){
			if (m-(a[n]-a[i])>=0){
				ans++;
				m-=(a[n]-a[i]);
			}else{
				cout << ans;
				return 0;
			}
		}
		cout << ans;
		return 0;
	}
	ans=1;
	if (ok1==1){
		for (int i=n-1;i>=1;i--){
			if (m-(a[n]-a[i])>=0){
				ans++;
				m-=(a[n]-a[i]);
			}else{
				cout << ans;
				return 0;
			}
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1);
	ll x=m;
	ans=-1e18;
	ll sum=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j>=1;j--){
			if (m-(abs(a[j]-a[i]))>=0){
				sum++;
				m-=abs(a[j]-a[i]);
			}else{
				ans=max(ans,sum);
				sum=0;
				m=x;
				break;
			}
		}
		ans=max(ans,sum);
		sum=0;
		m=x;
	}
	cout << ans;
	return 0;
}
