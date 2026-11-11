#include<bits/stdc++.h>
using namespace std;
const int MAXX=5e5+78;
int n,m,sum;
long long a[MAXX];
long long b[MAXX];
int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n-1; i++) {
		sum+=a[n]-a[i];
	}
	if(sum<=m) {
		cout<<n;
		return 0;
	} else {
		for(int i=n-1; i>=1; i--) {
			long long p=a[n]-a[i];
			if(sum-p*i<=m) {
				cout<<i;
				return 0;
			} else {
				sum-=p*i;
			}
		}
	}
	return 0;
}
//Oct31==Dec25?
