#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int ck(int x) {
	long long sum=0;
	for (int i=n;i>=x;i--) {
		for (int j=i;j>=i-x+1;j--) {
			sum+=(a[i]-a[j]);
		}
		if (sum<=m) return 1;
		sum=0;
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int g=a[2]-a[1],f=0;
	for (int i=3;i<=n;i++) {
		if (a[i]-a[i-1]!=g) {
			f=1;
			break;
		}
	}
	if (!f) {
		for (int i=1;i<=n;i++) {
			b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
			if (b[i]>m) {
				cout<<i-1<<endl;
				break;
			}
		}
		if (b[n]<=m&&b[n]!=0) cout<<n<<endl;
	} else {
		int l=1,r=n,ans=0;
		while (l<=r) {
			int mid=(l+r)/2;
			if (ck(mid)) {
				ans=mid;
				l=mid+1;
			} else r=mid-1;
		}
		cout<<ans<<endl;	
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
