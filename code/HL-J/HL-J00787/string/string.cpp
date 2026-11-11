#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=2e5+100;
int n,l,r;
ll a[N],pre[N],lx,rx,sum,ans=0;
char c[N]; 
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	bool okok=true;
	for(int i=1;i<n;i++) {
		if(c[i]!=c[i+1]) okok=false;
	}
	if(okok) {
		cout<<0;
		return 0;
	}
	if(n==1) {
		cout<<0;
		return 0;
	}
	if(n==2) {
		if(a[1]==a[2]||int(abs(a[1]-a[2]))){
			cout<<a[1];
			return 0;
		}
		if((a[1]+a[2]%2==1)){
			if(a[1]>a[2]) a[1]--;
			else a[2]--;
		}
		ll mid=(a[1]+a[2])/2;
		ll mn=min(a[1],a[2]);
		cout<<min(mid-mn,mn);
		return 0;
	}
	lx=rx=1;l=1;r=n;
//	while(l<=r&&c[l]!=c[r]) {
//		lx+=a[l];rx+=a[r];l++;r++;
//	}
//	if(l>=r) {
//		cout<<0;
//		return 0;
//	}
	while(lx<=sum/2&&rx<=sum/2) {
//		if(l+1==mid&&r+1==mid) break;
//		if(l+1==mid) {
//
//		}
		ll nl=lx,nr=rx;
		if(lx<=rx) {
			nl+=a[l];l++;
			if(c[l-1]!=c[r])
				ans+=min(nl-1,rx)-lx;
			lx=nl;
		}
		else {
			nr+=a[r];r--;
			if(c[l]!=c[r+1])
				ans+=min(nr-1,lx)-rx;
			rx=nr;
		}
	}
	
	if(l==r)
	cout<<ans<<'\n';
	return 0;
}