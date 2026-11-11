#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	ll avg=0;
	vector<ll> a(n+1);
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a.begin()+1,a.end());
	if(n<=5000) {

		ll maxn = 0;
		for(int i=1; i<=n; i++) {
			ll c= 0,cmx = 1;
			for(int j=i-1; j>=1; j--) {
				c+=a[i] - a[j];
				if(c<=m) cmx++;
				else break;
			}
			maxn = max(maxn,cmx);
		}
		cout << maxn << endl;
	}else
	{
		int i;
		ll k = 0;
		for(i=1;i<n;i++)
		{
			k+= (a[i+1]-a[i])*i;
			if(k>m) break;
		}
		cout << i << endl;
	}
	return 0;
}
