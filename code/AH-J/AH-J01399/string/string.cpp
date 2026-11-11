#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int l,r,lrest,rrest,n,ans;
char a[N];
int b[N];
char lc,rc;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>b[i]>>a[i];
	}
	l=1,r=n,lrest=b[1],rrest=b[n];
	lc=a[1],rc=a[n];
	while(l<=r) {
		if(lrest>rrest) {
			if(lc!=rc) {			
				lrest-=rrest;
				ans+=rrest;
				r--;
				rrest=b[r];
				rc=a[r];
			}
			else if(lc==rc) {
				lrest-=rrest;
				r--;
				rrest=b[r];
				rc=a[r];
			}
		}
		else if(rrest==lrest) {
			if(lc!=rc) {			
				ans+=rrest;
				r--;
				l++;
				rrest=b[r];
				lrest=b[l];
				lc=a[l],rc=a[r];
			}
			else if(lc==rc) {
				l++;
				r--;
				rrest=b[r];
				lrest=b[l];
				lc=a[l],rc=a[r];
			}
		}
		else if(lrest<rrest) {
			if(lc!=rc) {			
				rrest-=lrest;
				ans+=lrest;
				l++;
				lrest=b[l];
				lc=a[l];
			}
			else if(lc==rc) {
				rrest-=lrest;
				l++;
				lrest=b[l];
				lc=a[l];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
