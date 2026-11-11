#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll ans;
ll a[200005];
char c[200005];
int n;
ll l,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	l=1,r=n;
	while(l<=r){
		if(l>=r) break;
		ll t=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=t;
		}
		a[l]-=t,a[r]-=t;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
