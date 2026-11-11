#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],ans,cnt;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		a[i]+=a[i-1];
	}
	cnt=a[n];
	ll id=n;
	for(ll i=1;i<=n;i++){
		ll l=min(a[i],(cnt+1)/2);
		ll rr=cnt-a[i-1],rl=cnt-l+1;
		while(a[id-1]+1>=rl){
			ll u=min(rr,a[id]);
			if(b[i]!=b[id])
				ans+=(u-a[id-1]);
			rr=a[id-1];
			id--;
		}
		if(b[i]!=b[id])
			ans+=(rr-rl+1);
		if(l==(cnt+1)/2)break;
	}
	cout<<ans<<endl;
	return 0;
}