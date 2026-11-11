#include<bits/stdc++.h> 
using namespace std;
const long long N=1e9+5,M=5*1e5+5;
long long c,n,m,d,q,k;
long long w[M],a[M],t[N],l[M],r[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){ 
		cin >> k;
		for(int j = 1;j <= k;j++) cin >> a[i] >> t[i];
	}
	for(int i = 1;i <= q;i++) cin >> l[i] >> r[i];
	return 0;
}
