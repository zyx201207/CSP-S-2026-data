#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int a[200010],sum[200010];
char c[200010];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int len=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		len+=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		int ls=sum[i]-a[i]+1,le=sum[i];
		if(ls>len/2) {
			break;
		} else if(le>=len/2) {
			le=len/2;
			int rs=len-le+1,re=len-ls+1;
			int pos1=lower_bound(sum,sum+n+1,rs)-sum;
			int pos2=lower_bound(sum,sum+n+1,re)-sum;
			for(int j=pos1; j<=pos2; j++) {
				int e=min(re,sum[j]),s=max(rs,sum[j]-a[j]+1);
				if(c[j]!=c[i]) {
					ans+=e-s+1;
				}
			}
			break;
		}
		int rs=len-le+1,re=len-ls+1;
		int pos1=lower_bound(sum,sum+n+1,rs)-sum;
		int pos2=lower_bound(sum,sum+n+1,re)-sum;
		for(int j=pos1; j<=pos2; j++) {
			int e=min(re,sum[j]),s=max(rs,sum[j]-a[j]+1);
			if(c[j]!=c[i]) {
				ans+=e-s+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
