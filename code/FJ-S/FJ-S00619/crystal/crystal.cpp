#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
const int N = 500005;
const ll INF = 1e17;
int n;
int tot;
ll ans;
ll m;
ll l=INF,r=-INF;
ll last,lres;
ll res;
ll a[N];
ll c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
		l=(l>a[i]?a[i]:l);
		r=(r<a[i]?a[i]:r);
	}
	sort(a+1,a+n+1);
	
	if (r-l>n) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				c[j]=a[i]-a[j];
				if (a[i]-a[j]>=0 && (a[i]-a[j+1]<0||j==n)) {
					tot=j;
					break;
				}
			}
			ll cnt=0;
			res=0;
			for (int i=tot; i>=1; i--) {
				if (m-cnt>=c[i]) {
					cnt+=c[i];
					res++;
				} else
					break;
			}
			if (ans<res)
				ans=res;
		}
	} else {
		for (int i=l; i<=r; i++) {
			for (int j=1; j<=n; j++) {
				c[j]=i-a[j];
				if (c[j]>=0 && (i-a[j+1]<0||j==n)) {
					tot=j;
					break;
				}
			}
			ll cnt=0;
			res=0;
			for (int i=tot; i>=1; i--) {
				if (m-cnt>=c[i]) {
					cnt+=c[i];
					res++;
				} else {
					break;
				}
			}
			if (ans<res)
				ans=res;
		}
	}
	cout<<ans;
	return 0;
}
