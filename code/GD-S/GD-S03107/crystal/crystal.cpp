#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll a[N],p[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=n;i>=1;i--){
		p[i]=p[i+1]+a[n]-a[i];
	}
	ll i=n,j=n,ans=1,d=0;
	while(j>1){
		while((j>1)&&(d+a[i]-a[j-1]<=m)){
			d+=a[i]-a[j-1];
			j--;
		}
		ans=max(ans,i-j+1);
		d-=(a[i]-a[i-1])*(i-j);
		i--;
		if(j>i){
			j--;
		}
	}
	cout<<ans;
	return 0;
}
