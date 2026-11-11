#include <iostream>
using namespace std;
const int N = 5e5 + 5;
int n,ans;
long long m,a[N];
bool check() {
	long long tmp=a[2]-a[1];
	for (int i=3; i<=n; i++)
		if (a[i]-a[i-1]!=tmp) return false;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long max_a=-1e12,min_a=1e12;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		max_a=max(max_a,a[i]);
		min_a=min(min_a,a[i]);
	}
	if (check()) {
		long long tmp=a[2]-a[1],k=tmp;
		for (int i=2; i<=n; i++) {
			m=m-k;
			if (m<0) {
				cout<<i-1<<endl;
				return 0;
			}
			k=k+tmp;
		}
		cout<<n<<endl;
		return 0;
	}
	int t=0,ans=0;
	for (long long i=min_a; i<=max_a; i++) {
		int cnt=0;
		long long sum=0;
		for (int j=1; j<=n; j++) {
			t++;
			if (a[j]>i) continue;
			sum=sum+(i-a[j]);
			if (sum<=m || a[j]==i) cnt++;
			if (t==1e8) break;
		}
		if (sum<=m) ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
