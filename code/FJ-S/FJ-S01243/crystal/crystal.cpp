#include<bits/stdc++.h>

using namespace std;

long long n,m,ans,sum[500005],A[500005];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i];
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+A[i];
	for(long long i=1;i<=n;i++) {
		int l=1,r=i,pos=0;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(A[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) pos=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}
