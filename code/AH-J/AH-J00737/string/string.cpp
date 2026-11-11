#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005];
ll ans;
char c[200005];
ll x,y;
ll sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
		ans+=a[i];
	}
	x=1,y=n;
	while(x<y){
		if(a[x]<=a[y]){
			if(c[x]!=c[y]){
				sum+=a[x];
			}
			a[y]-=a[x];
			x++;
		}else{
			if(c[x]!=c[y]){
				sum+=a[y];
			}
			a[x]-=a[y];
			y--;
		}
	}
	cout<<sum;
	return 0;
}
