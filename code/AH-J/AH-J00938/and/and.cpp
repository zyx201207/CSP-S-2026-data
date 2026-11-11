#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
			}
		cout<<ans;
		return 0;
		}
	else if(m==1){
		ll maxn=-1e18;
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
			}
		cout<<maxn;
		return 0;
		}
	else if(m==2){
		ll maxn=-1e18;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>maxn) maxn=(a[i]&a[j]);
				}				
			}
			cout<<maxn;
			return 0;
		}
		else if(m==n-1){
			ll ans[100005];
			ans[1]=a[2];
			for(int i=3;i<=n;i++) ans[1]&=a[i];
			for(int i=2;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j)ans[i]&=a[j];
					}
			}
			ll maxn=-1e18;
			for(int i=1;i<=n;i++) maxn=max(ans[i],maxn);
			cout<<maxn;
			return 0;
			}
	ll ans=a[n];
	sort(a+1,a+n+1);
	for(int i=n-1;i>n-m;i--){
		ans&=a[i];
		}
	cout<<ans;
	return 0;
}
