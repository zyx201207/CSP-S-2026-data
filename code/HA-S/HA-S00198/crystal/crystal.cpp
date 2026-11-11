#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
#define H <<' '<<
using namespace std;
ll n,m,a[500005],ans,d,fff;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
//	freopen("crystal/crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	d=a[2]-a[1];
	fff=1;
	for(ll i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			fff=0;
			break;
		}
	}
	if(fff){// A,B
		if(d==0){
			cout<<n;
			return 0;
		}
		ll i=0,j=0,c=0;
		for(;;){
			i+=d;
			j+=i;
			if(j>m){
				break;
			}
			c++;
			if(c==n-1){
				break;
			}
		}
		cout<<c+1;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		if(a[i]!=n&&a[i]==a[i+1]){
			continue;
		}
		ll c=1,s=0;
		for(ll j=i-1;j>=1;j--){
			if(s+a[i]-a[j]<=m){
				s+=a[i]-a[j];
				c++;
			}else{
				break;
			}
		}
		ans=max(ans,c);
	}
	cout<<ans;
	return 0;
}
// 75
