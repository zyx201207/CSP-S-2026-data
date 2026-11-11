#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n,m;
int a[N];

int c[N];
int qc[N];
int q[N];

bool check(int l,int r) {
	return (r-l+1)*qc[r]-(q[r]-q[l-1])<=m;
}

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	
	sort(a+1,a+1+n);
	
	for(int i=2;i<=n;i++) {
		c[i]=a[i]-a[i-1];
	}
	
	for(int i=1;i<=n;i++) {
		qc[i]=qc[i-1]+c[i];
	}
	
	for(int i=1;i<=n;i++) {
		q[i]=q[i-1]+qc[i];
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++) {
		int l=i,r=n,d=i;
		
		while(l<=r) {
			int mid=l+r>>1;
			
			if(check(i,mid)) {
				d=mid;
				l=mid+1;
			} 
			else {
				r=mid-1;
			}
		}
		
		ans=max(ans,d-i+1);
	}
	
	printf("%lld",ans);
	return 0;
}
