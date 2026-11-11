#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i=a; i<=b; ++i)
#define F_(i,a,b) for(int i=a; i>=b; i--)
#define pii pair<int,int>
#define fr first
#define sc second
#define pb push_back
const int N = 1e6+10;
int n,ans;
ll m,ar[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	F(i,1,n) cin >> ar[i];
	sort(ar+1,ar+n+1);
	F(i,1,n) sum[i] = sum[i-1]+ar[i];
	F(i,1,n){
		int l = 1, r = i;
		while (l <= r){
			int mid = (l+r)>>1;
			if (ar[i]*(i-mid+1) - (sum[i]-sum[mid-1]) <= m) r = mid-1;
			else l = mid+1;
		}
		ans = max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
