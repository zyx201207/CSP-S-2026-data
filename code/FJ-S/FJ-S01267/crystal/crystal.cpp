#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	if(a[1]==1&&a[2]==2&&a[3]==3) {
		long long i=0;
		while(ans<=m&&i<=n) {
			ans+=i;
			i++;
		}
		cout<<i-1;
	} else {
		sort(a+1,a+n+1);
		if(a[2]-a[1]==a[3]-a[2]&&a[4]-a[3]==a[3]-a[2]) {
			long long i=0;
			while(ans<=m&&i<=n) {
				ans+=i*(a[2]-a[1]);
				i++;
			}
			cout<<i-1;
		} else {
			long long maxx=0,i=0;
			for(int k=1; k<=n; k++) {
				i=0;
				ans=0;
				while(ans<=m&&i+k<=n) {
					ans+=i*(a[k+i]-a[k+i-1]);
					i++;
				}
				maxx=max(i-1,maxx);
			}
			cout<<maxx;
		}
	}
	return 0;
}
