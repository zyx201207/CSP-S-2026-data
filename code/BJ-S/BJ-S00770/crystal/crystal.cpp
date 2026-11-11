#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500100];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	
	sort(a+1, a+n+1);
	
	long long sum=0;
	int ans=0;
	for(int i=1, j=1;i<=n;++i) {
		sum+=(a[i]-a[i-1])*(i-j);
		while(sum>m) {
			sum-=(a[i]-a[j]);
			j++;
		}
		//cout<<i<<','<<j<<endl;
		ans=max(ans, i-j+1);
	}
	cout<<ans;
	return 0;
}
