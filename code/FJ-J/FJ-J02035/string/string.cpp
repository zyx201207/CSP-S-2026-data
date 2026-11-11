#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<r){
		ll d=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=d;
		}
		a[l]-=d,a[r]-=d;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans<<endl;
	return 0;
}
