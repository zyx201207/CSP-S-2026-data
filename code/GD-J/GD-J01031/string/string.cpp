#include<bits/stdc++.h>
#define int long long
#define N 200005

using namespace std;

int n,ans,a[N],l,ll,r,rr;
char c[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	l = 1,r = n;
	for(int i = 1;i <= n;i++)cin >> a[i] >> c[i];
	while(l < r){
		int lll = a[l] - ll,rrr = a[r] - rr;
		if(c[l] != c[r])ans += min(lll,rrr);
		ll += min(lll,rrr),rr += min(lll,rrr);
		if(a[l] - ll == 0)l++,ll = 0;
		if(a[r] - rr == 0)r--,rr = 0;
	}
	cout << ans << "\n";
	return 0;
}
