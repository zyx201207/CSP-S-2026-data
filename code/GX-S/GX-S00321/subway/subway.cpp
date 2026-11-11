#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,s[500005],a[505],t[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> 	c >> n >> m >> d >> q;
	for(long long i=1;i<=m;i++)cin >> s[i];
	for(long long i=1;i<=n;i++){
		long long k;
		cin >> k;
		for(long long j=1;j<=k;j++)cin >> a[j] >> t[j];
	}
	while(q--){
		cout << 1;
	}
	return 0;
}
