#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
	}
	ll l=1,r=n,cnt=0;
	while(l<=r){
		if(a[l]>=a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[l]-=a[r];
				cnt+=a[r];
				r--;
			}
		}
		if(a[l]<a[r]){
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				a[r]-=a[l];
				cnt+=a[l];
				l++;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}
