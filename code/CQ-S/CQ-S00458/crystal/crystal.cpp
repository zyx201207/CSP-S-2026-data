#include <bits/stdc++.h>
#define re register
#define int long long
#define chmax(a,b) (a = max(a,b))

using namespace std;

const int N = 5e5 + 10;
int n,m,ans;
int a[N],s[N];

inline int read(){
	int r = 0,w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		r = (r << 1) + (r << 3) + (c ^ 48);
		c = getchar();
	}
	return r * w;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(),m = read();
	for (re int i = 1;i <= n;i++) a[i] = read();
	sort(a + 1,a + n + 1);
	for (re int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	for (re int i = 1;i <= n;i++){
		int l = 1,r = i;
		while (l < r){
			int mid = (l + r >> 1);
			if ((i - mid + 1) * a[i] - (s[i] - s[mid - 1]) <= m) r = mid;
			else l = mid + 1;
		} chmax(ans,i - l + 1);
	} printf("%lld",ans);
	return 0;
}
