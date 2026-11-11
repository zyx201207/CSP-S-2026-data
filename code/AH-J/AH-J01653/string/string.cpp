#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,n,a[200005],lt,rt,ans,sum;
char c[200005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i] >> c[i];
		sum+=a[i];
	}
	l=1,r=n,lt=a[1],rt=a[n],ans=(c[1]==c[n]?0:min(a[1],a[n]));
	sum=sum/2;
	for(; l<r; ) {
		lt=min(lt,sum),rt=min(rt,sum);
		if(lt>rt) {
			r--;
			if(l>=r) break;
			if(c[r]!=c[l]) ans+=min(a[r],lt-rt);
			rt+=a[r];
		}
		else if(lt==rt){
			l++,r--;
			if(l>=r) break;
			if(c[r]!=c[l]) ans+=min(a[l],a[r]);
			lt+=a[l],rt+=a[r];
		}
		else {
			l++;
			if(l>=r) break;
			if(c[r]!=c[l]) ans+=min(a[l],rt-lt);
			lt+=a[l];
		}
	}
	cout << ans;
	return 0;
}
