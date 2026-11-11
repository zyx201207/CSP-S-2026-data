#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long orb[500005];
long long ans[500005];
long long z;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) {
		cin>>orb[i];
	}
	sort(orb+1,orb+n+1);
	for(long long i=2;i<=n;i++) {
		int mm=m;
		for(long long j=i-1;j>=1;j--) {
			if (orb[i]-orb[j]<=mm) {
				ans[z]++;
				mm=mm-orb[i]+orb[j];
			} else {
				break;
			}
		}
		z++;
	}
	sort(ans+1,ans+n+1);
	cout<<ans[n]+1;
	return 0;
}
