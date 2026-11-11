#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200010],ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i];
	ll l=1,r=n;
	while(l<r){
		ll sum=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=sum;
		a[l]-=sum;
		a[r]-=sum;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
