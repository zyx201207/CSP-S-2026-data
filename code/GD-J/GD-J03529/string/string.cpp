#include<bits/stdc++.h>
#define ll long long
#define fi(x) freopen(x".in","r",stdin)
#define fo(x) freopen(x".out","w",stdout)
#define wc(x) fi(x);fo(x)
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;
const int N=2e5+10;
int n,l,r;	
ll a[N],ans;
char c[N];
int main() {
	wc("string");
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];	
	l=1,r=n;
	while(l<r) {
		if(a[l]!=a[r] or c[l]!=c[r]) {
			ll sum=0;
			while(sum<a[l]) {
				if(sum+a[r]>a[l]) {
					if(c[r]!=c[l]) ans+=a[l]-sum;
					a[r]-=a[l]-sum;
					break;
				} 
				if(c[r]!=c[l]) ans+=a[r];
				sum+=a[r];
				r--;
			} 
			l++;
		} else {
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}

