#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,a[N];
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	ll ans=0,fz1=0,fz2=0;
	for(ll i=1,j=n; i<=j && j>=i; i++,j--) {
		if(c[i]!=c[j] || (c[i]==c[j] && a[i]!=a[j])) {
			if(a[i]>a[j]) {
				ans+=a[i]-a[j];
				fz2+=a[i]-a[j];
				fz1=max(0,int(fz1-a[i]+a[j]));
			} else if(a[i]<a[j]) {
				ans+=a[j]-a[i];
				fz1+=a[j]-a[i];
				fz2=max(0,int(fz2-a[j]+a[i]));
			}else{
				ans+=a[i];
			}
		}
	}
	cout<<ans+fz1+fz2;
	return 0;
}

