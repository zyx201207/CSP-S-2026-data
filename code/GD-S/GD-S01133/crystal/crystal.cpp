#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;ll m;cin>>n>>m;
	vector<ll>a(n+1);
	vector<ll>b(n+2);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=n-1;i>=1;i--){
		b[i]=b[i+1]+a[n]-a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int l=i-1,r=n+1;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(b[i]-b[mid+1]-(mid-i+1)*(a[n]-a[mid])<=m)l=mid;
			else r=mid;
		}
		if(l-i+1>ans)ans=l-i+1;
	}
	cout<<ans<<'\n';
	return 0;
}
