#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,a[N],d[N],ans[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++) cin>>a[i];
	if(m==0) {
		ll maxn=1,ans=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) {
			if(a[i]==a[i+1]) maxn++;
			else {
				ans=max(maxn,ans);
				maxn=1;
			}
		}
		cout<<ans; return 0;
	}
	bool t=1;
	for(int i=1;i<=n;i++) if(a[i]!=i) {
		t=0; break;
	}
	if(t==1) {
		ll ans=0;
		for(int i=1;i<=n;i++) {
			ll sum=i*(i-1)/2;
			if(sum<=m) ans=sum;
			else break;
		}
		cout<<ans;
		return 0;
	}
	bool t1=1;
	for(int i=1;i<=n;i++) {
		d[i]=a[i]-a[i-1];
		if(d[i]!=d[i-1]){
			t1=0;
			break;
		}
	}
	if(t1==1) {
		ll q=d[2]-d[1],ans=0;
		for(int i=1;i<=n;i++){
			ll sum=(a[1]+a[i])*(i-1)/q;
			if(sum<=m) ans=sum;
			else break;
		} cout<<ans; return 0;
	}
	sort(a+1,a+n+1);
	ll sum,ans=0;
	for(int i=1;i<=n;i++) {
		int k=m;
		sum=0;
		for(int j=i-1;j>=1;j--) {
			if(a[i]-a[j]<=k) {
				k-=a[i]-a[j];
				sum++;ans=max(sum,ans);
			}else break; 
		}
	}
	cout<<ans+1;
} 
