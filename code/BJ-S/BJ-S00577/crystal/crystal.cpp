#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[500005];
int main(){
	freopen("./crystal.in","r",stdin);
    freopen("./crystal.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    for(ll i=1;i<=n;i++)cin >> a[i];
    if(n==1){
		cout << a[1] << endl;
		return 0;
	}
    sort(a+1,a+n+1);
    ll mid=(n%2==0)?n/2:(n+1)/2;
    ll ans=0;
    ll k=m;
    for(ll i=mid-1;i>=1&&k;i--){
        //选择中位数，然后从中位开始向前面枚举看多少次能将k耗完
        ll sk=a[mid]-a[i];
        if(k-sk>=0){
            ans++;
            k-=sk;
        }
    }
    ll mr=0;
    for(ll i=mid;i<=n;i++){
		if(a[i]!=a[mid])break;
		if(a[i]==a[mid])mr++;
	}
    printf("%lld\n",(ans+mr));
}
