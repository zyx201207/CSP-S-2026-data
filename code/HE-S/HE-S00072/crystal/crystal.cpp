#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
//typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int,int> P;
const int N=5e5+5;
int n,m,a[N];
int ans=1;
bool cmp1(int x,int y) {
	return x<y;
}

signed main() {
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);


	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp1);

	int l=1,r=1,sum=0;
	while(r<=n) {
		sum+=(r-l)*(a[r]-a[r-1]);
//		cout<<l<<' '<<r<<' '<<sum<<' '<<ans<<' '<<r-l*(a[r]-a[r-1])<<endl;
		while(l<=r&&r<=n&&sum>m) {
			sum-=(a[r]-a[l]);
			l++;
		}

		if(sum>m) {
			if(l==r) {
				l++,r++;
				sum=0;
				continue;
			} else {
				r++;
				continue;
			}
		}
		ans=max(r-l+1,ans);
		r++;
	}

	cout<<ans;
	return 0;
}
