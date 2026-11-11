#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+5;
ll a[N];
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll p=n,sum=a[n],ans=1;
	for(int i=n;i>=1;i--){
		sum-=a[i];
		while((i-p+1)*a[i]-sum-a[p-1]<=m&&p>1){
			p--;
			sum+=a[p];
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	
	
	return 0;
}
