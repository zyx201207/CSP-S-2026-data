#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],b[N],sum,s[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		if(i>=2) {
			b[i]=a[i]-a[i-1];
			s[i]=b[i]+s[i-1];
		}
	}
	int l=2,r=n;
	while(l<r) {
		int mid=(l+r)/2;
		if(b[l]<=b[r]) {
			r=mid;
		} else if(b[l]>b[r]) {
			l=mid;
		}
	}
	int x=l+1;
	int l2=l;
	int r2=l+2;
	while(m>0) {
		if(l2<0) {
			if(m<s[r2]-s[l]) {
					cout<<sum;
					return 0;
				} else {
					m-=(s[r2]-s[l]);
					r2++;
					sum++;
				}
		} else if(r2>n) {
			if(m<s[l]-s[l2]) {
					cout<<sum;
					return 0;
				} else {
					
					l2--;
					sum++;
				}
		} else if(l2>=0&&r2<=n){
			if(s[l]-s[l2]<=s[r2]-s[l]) {
				if(m<s[l]-s[l2]) {
					cout<<sum;
					return 0;
				} else {
					m-=(s[l]-s[l2]);
					l2--;
					sum++;
				}
			} else if(s[l]-s[l2]>s[r2]-s[l]&&r2<=n) {
				if(m<s[r2]-s[l]) {
					cout<<sum;
					return 0;
				} else {
					m-=(s[r2]-s[l]);
					r2++;
					sum++;
				}
			}
		}else if(l2<0&&r2>n){
			cout<<sum;
			return 0;
		}
	}
}
