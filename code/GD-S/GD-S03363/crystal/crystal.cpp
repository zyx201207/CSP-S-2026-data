#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500005;
ll n,m;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) s[i]=s[i+1]+a[i];
	int ans=1;
	for(int i=n;i>=1;i--){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if((i-mid)*1ll*a[i]-(s[mid]-s[i])<=m) r=mid;
			else l=mid+1;
		}ans=max(ans,(i-l+1));
	}cout << ans;
	return 0;
}
