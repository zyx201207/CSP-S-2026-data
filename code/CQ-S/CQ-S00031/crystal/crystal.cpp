#include <bits/stdc++.h>
#define name "crystal"
using namespace std;
const int N=500007;
typedef long long li;
li a[N],s[N];
int main(){
	freopen(name".in","r",stdin);
	freopen(name".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	li n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	li ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(1ll*(i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1ll);
	}
	cout<<ans<<'\n';
	return 0;
} 
/*
CSP-S rp += inf
NOIP rp += inf
Never give up any problems as I have lost NOIP2025.
See ancestors on Halloween at /discuss/898803.
//froepen
//ferepen
//retrun
qwq
qwqwq
qwqwqwq
qwqwqwqwq
qwqwqwqwqwq
*/
