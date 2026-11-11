#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	long long n,m,ans=-1e18-1;
	bool f=1;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		if(a[i]-a[i-1]!=1) {
			f=0;
		}
	}
	if(f) {
		long long i=1,l=1;
		while(1) {
			if(m>=i) {
				m-=i;
				l++;
				i++;
			} else {
				break;
			}
		}
		cout << l;
		return 0;
	}
	sort(a,a+n);
	for(int i=1; i<n; i++) {
		long long
		k=m,j=1,sum=1;
		while(k>=a[i]-a[i-j]&&i-j>=0) {
			k-=a[i]-a[i-j];
			j++;
			sum++;
		}
		ans=max(ans,sum);
	}
	cout << ans;
	return 0;
}
