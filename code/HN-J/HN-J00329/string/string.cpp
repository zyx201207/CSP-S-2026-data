#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
char c[N];
long long n,a[N],ans,len;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long l=0,r=n,ll=0,rr=0;
	while(ll<=len/2) {
		long long sum=0,cnt=0;
		l++;
		ll+=a[l];
		while(true) {
			sum+=a[r];
			if(sum>=a[l]) {
				a[r]-=a[l]-cnt;
				if(c[l]!=c[r]) ans+=a[l]-cnt;
				break;
			}else{
				cnt+=a[r];
				if(c[l]!=c[r]) ans+=a[r];
			}
			
			r--;
		}
		//cout<<ll<<' '<<l<<' '<<r<<' '<<ans<<' '<<a[r]<<c[l]<<' '<<c[r]<<endl;
		//if(c[l]!=c[r]) ans+=a[l];
		sum=0;
	}
	cout<<ans;
	return 0;
}
